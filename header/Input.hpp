#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#include <iostream>
#include <string>

#include "ExecuteDecorator.hpp"

using namespace std;

class Input : public ExecuteDecorator
{
	private:
		CommandBase* cmd;

	public:
		/* Constructors */
		Input() {};
		Input(CommandBase* cmd_) { this->cmd = cmd_; };

		~Input() { delete cmd; }

		virtual int execute() 
		{
			int new_in = 0; 
			return this->cmd->execute(); 
		};
};

#endif
