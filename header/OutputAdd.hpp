#ifndef __OUTPUT_ADD_HPP__
#define __OUTPUT_ADD_HPP__

#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "ExecuteDecorator.hpp"

using namespace std;

class OutputAdd : public ExecuteDecorator
{
	private:
		CommandBase* cmd;
		string file;

	public:
		/* Constructors */
		OutputAdd(CommandBase* cmd_, string file) { this->cmd = cmd_; this->file = file;};

		/* Destructor */
		~OutputAdd() { delete cmd; };

		virtual int execute()
		{
			int new_out = open(file.c_str(), O_WRONLY | O_CREAT | O_APPEND);
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
