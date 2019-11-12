#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

#include "CommandBase.hpp"
#include <string>

using namespace std;

class Command: public CommandBase{
   private:
	char* cmd_args[];
   public:
	Command(char* cmdargs[]){
		this->cmd_args = cmdargs;
	}

	virtual int execute();
};

#endif
