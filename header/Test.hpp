#ifndef _TEST_HPP_
#define _TEST_HPP_

#include "CommandBase.hpp"
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

class ShellTest: public CommandBase{
     private:
	vector<string> args;
     public:
	ShellTest(const vector<string>& cmdargs){
		for(int i = 0;i < cmdargs.size();i++){
			args.push_back(cmdargs.at(i));
		}
	}

	virtual int execute(){
		int result;
		int filepath = 0;
		int flag = 0;
		char flagC;

		if(args.at(0).at(0) == '-' && args.at(filepath).size() >= 2){
			filepath = 1;
			flagC = args.at(0).at(1);
			if(flagC == 'd'){ flag = 1; }
			else if(flagC == 'f'){ flag = 2; }
		}

		struct stat buffer;
		result = stat(args.at(filepath).c_str(), &buffer);

		if(flag == 0){
			if(result == 0){
				std::cout << "(True)" << std::endl;
				return 0;
			}
			else{
				std::cout << "(False)" << std::endl;
				return 1;
			}
		}
		else if(flag == 1){
			if(result == 0){
				if(S_ISDIR(buffer.st_mode) != 0){
					std::cout << "(True)" << std::endl;
                                	return 0;
				}
				else{
					std::cout << "(False)" << std::endl;
                                	return 1;
				}
			}
			else{
				std::cout << "(False)" << std::endl;
                                return 1;
			}
		}
		else{
			if(result == 0){
				if(S_ISREG(buffer.st_mode) != 0){
					std::cout << "(True)" << std::endl;
                                        return 0;
				}
				else{
                                        std::cout << "(False)" << std::endl;
                                        return 1;
				}
			}
			else{
				std::cout << "(False)" << std::endl;
                                return 1;
			}		
		}
		
	}
};

#endif
