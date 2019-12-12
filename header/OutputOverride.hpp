#ifndef __OUTPUT_OVERRIDE_HPP__
#define __OUTPUT_OVERRIDE_HPP__

#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "ExecuteDecorator.hpp"

using namespace std;

class OutputOverride : public ExecuteDecorator
{
	private:
		CommandBase* cmd;
		string file;

	public:
		/* Constructors */
		OutputOverride(CommandBase* cmd_, string file): ExecuteDecorator() { this->cmd = cmd_; this->file = file;};

		/* Destructor */
		~OutputOverride() { delete cmd; };

		virtual int execute()
		{
			int new_out = open(file.c_str(), O_RDWR | O_CREAT);
			int dupout = dup(1);
			close(1);
			dup(new_out);
			int rtrn = this->cmd->execute();
			close(1);
			dup(dupout);
			close(new_out);
			
			return rtrn;
		};
};

#endif
