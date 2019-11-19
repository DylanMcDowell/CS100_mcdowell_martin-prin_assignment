#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

#include "CommandBase.hpp"
#include <string>
#include <vector>

using namespace std;

class Command: public CommandBase{
   private:
	vector<string> cmd_args;
   public:
	Command(const vector<string>& cmdargs){
		for(int i = 0; i < cmdargs.size(); i++){
			cmd_args.push_back(cmdargs.at(i));
		}
	}

	virtual int execute();
};

#endif
