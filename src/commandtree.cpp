#include "../header/CommandTree.hpp"
#include <iostream>

CommandBase* CommandTree::buildRec(int beg, int end){
	if(beg > end){
		return nullptr;
	}

	CommandBase* left;
	CommandBase* right;

	int parenNum = 0;//For parentheses addition
	
	//**COMPOSITE BLOCK**//

	//This for loop functions as a way to generate Connectors within the tree.
	//It also accounts for parentheses, and skips over them when parenNum,
	// which counts how many parentheses pairs have been closed (we go 
	// backward, remember?) and opened, is not zero. 

	for(int i = end; i >= beg; i--){
		if(parsed.at(i) == "("){
			parenNum++;
		}
		else if(parsed.at(i) == ")"){
			parenNum--;
		}

		else if(parsed.at(i) == "||" && parenNum == 0){
			left = this->buildRec(beg, i-1);
			right = this->buildRec(i+1, end);
			if(!left || !right){
				return nullptr;
			}
			return new OrBars(left, right);
		}

		else if(parsed.at(i) == "&&" && parenNum == 0){
                        left = this->buildRec(beg, i-1);
                        right = this->buildRec(i+1, end);
                        if(!left || !right){
                                return nullptr;
                        }
                        return new Ampersand(left, right);
                }

		else if(parsed.at(i) == ";" && parenNum == 0){
			left = this->buildRec(beg, i-1);
                        right = this->buildRec(i+1, end);
                        if(!left || !right){
                                return nullptr;
                        }
                        return new SemiColon(left, right);
                }

	}

	if(parenNum != 0){//Check to ensure that parentheses are matching
		std::cout << "ERROR: Nonmatching Parentheses" << std::endl;
		return nullptr;
	}

	//END COMPOSITE BLOCK//

	//**LEAF BLOCK**//

	//This will remove outer parentheses now that we are 
	// out of the connector block. It will then build a new
	// subtree with what was in the parentheses
	if(parsed.at(beg) == "(" && parsed.at(end) == ")"){
		return this->buildRec(beg+1, end-1);
	}
	else{
		return this->buildLeaf(beg, end);

	}

	//END LEAF BLOCK//
}


CommandBase* CommandTree::buildLeaf(int beg, int end){


	vector<string> cmd;
        for(int j = beg; j <= end; j++){
                cmd.push_back(parsed.at(j));
        }


        if(cmd.at(0) == "exit"){
                return new Exit();
        }
        else if(cmd.at(0) == "test" || cmd.at(0) == "["){
                for(int j = 1; j < cmd.size(); j++){
                        cmd.at(j-1) = cmd.at(j);
                }
                return new ShellTest(cmd);
        }
        else{
                return new Command(cmd);
        }
}

void CommandTree::parse(){
	parsed.clear();
	string line;
	Parser* parser = new Parser();
	std::cout << "$ " << std::flush;
	std::getline(cin, line);
	parsed = parser->parseLine(line);
	delete parser;
}

void CommandTree::buildTree(){
	
	while(root == nullptr){
		this->parse();
		root = this->buildRec(0, parsed.size()-1);
		if(root == nullptr){
			std::cout << "Fatal Error. Please re-enter input." << std::endl;
		}
	}	
}

void CommandTree::execute(){
	if(root != nullptr){
		root->execute();
	}
}

void CommandTree::vectorBuild(vector<string> v){
	parsed.clear();
	for(int i = 0; i < v.size(); i++){
		parsed.push_back(v.at(i));
	}
	root = this->buildRec(0, parsed.size()-1);
	if(root == nullptr){
		std::cout << "Fatal Error." << std::endl;
		parsed.clear();
	}
}
