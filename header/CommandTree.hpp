#ifndef _COMMANDTREE_HPP_
#define _COMMANDTREE_HPP_

#include "CommandBase.hpp"
#include "Command.hpp"
#include "exit.hpp"
#include "Connector.hpp"
#include "Ampersand.hpp"
#include "OrBars.hpp"
#include "SemiColon.hpp"

class CommandTree{
      private:
	//Data Members
	CommandBase* root;
	vector<string> parsed;

	//Private Functions

	/*Takes in two ints representing the location of the begining and end of the parsed vector
	 * and recursively splits it into commands and connectors by calling itself when it
	 * finds a connector */ 
	CommandBase* buildRec(int, int);

	//Calls the CommandParse class and it's parse function, then sets parsed equal to the result;
	void parse();
      public:

	//Constructor
	CommandTree() {}

	//Deconstructor
	~CommandTree(){ delete root;}

	//Forms a tree by calling parse(), then buildRec(...) on the whole vector.
	void buildTree();

	//Calls execute() on root
	void execute();
	
};

#endif //_COMMANDTREE_HPP_
