#ifndef __OUTPUT_OVERRIDE_HPP__
#define __OUTPUT_OVERRIDE_HPP__

#include <iostream>
#include <stdlib>
#include <string>
#include <unistd.h>

#include "ExecuteDecorator.hpp"

using namespace std;

class OuputOverride : public ExecuteDecorator
{
	private:
		CommandBase* cmd;

	public:
		/* Constructors */
		OutputOverride() {};
		OutputOverride(CommandBase* cmd_;) { this->cmd = cmd_; };

		/* Destructor */
		~OutputOverride() { delete cmd; };

		virtual int execute()
		{
			int new_out = open(file, O_WRONLY | O_CREAT);
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
