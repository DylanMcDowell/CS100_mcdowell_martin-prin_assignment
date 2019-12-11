#ifndef __EXECUTE_DECORATOR_HPP__
#define __EXECUTE_DECORATOR_HPP__

#include <iostream>
#include <string>

#include "CommandBase.hpp"

using namespace std;

class ExecuteDecorator : public CommandBase
{
	private:
		CommandBase* cmd;

	public:
		/* Constructor */
		ExecuteDecorator() {};
		ExecuteDecorator(CommandBase* cmd_) { this->cmd = cmd_; };

		virtual int execute() = 0;	
};

#endif
