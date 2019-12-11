#ifndef _PIPE_HPP_
#define _PIPE_HPP_

#include <unistd.h>

#include "Connector.hpp"

class Pipe : public Connector
{
      public:

	Pipe(CommandBase* l, CommandBase* r): Connector(l, r){}

	virtual int execute(){
		int pipeFD[2];
		int result;

		pipe(pipeFD);

		int dupout = dup(1);
		close(1);
		dup(pipeFD[1]);
		result = left->execute();
		close(1);
		dup(dupout);

		if(result = 0){
		int dupin = dup(0);
			close(0);
			dup(pipeFD[0]);
			result = right->execute();
			close(0);
			dup(dupin);
		}

		close(pipeFD[1]);
		close(pipeFD[2]);
		return result;
	}
};

#endif //_PIPE_HPP_
