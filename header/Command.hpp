#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

#include "CommandBase.hpp"
#include <string>

using namespace std;

class Command: public CommandBase{
   private:
	string cmd_args;
   public:
	Command(string cmd_args){
		this->cmd_args = cmd_args;
	}

	virtual int execute(){
		return 0;
	}
}

#endif
