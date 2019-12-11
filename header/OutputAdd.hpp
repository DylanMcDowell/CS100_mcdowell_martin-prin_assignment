#ifndef __OUTPUT_ADD_HPP__
#define __OUTPUT_ADD_HPP__

#include <iostream>
#include <stdlib>
#include <string>
#include <unistd.h>

#include "ExecuteDecorator.hpp"

using namespace std;

class OuputAdd : public ExecuteDecorator
{
	private:
		CommandBase* cmd;

	public:
		/* Constructors */
		OutputAdd() {};
		OutputAdd(CommandBase* cmd_;) { this->cmd = cmd_; };

		/* Destructor */
		~OutputAdd() { delete cmd; };

		virtual int execute()
		{
			int new_out = open(file, O_WRONLY | O_CREAT | O_APPEND);
			int dupout = dup(1);
			close(1);
			dup(new_out);
			int rtrn = this->cmd->execute();
			close(1);
			dup(dupout);
			close(file);
			
			return rtrn;
		};
};

#endif
