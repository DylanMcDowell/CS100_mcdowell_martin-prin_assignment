#ifndef __EXECUTE_DECORATOR_HPP__
#define __EXECUTE_DECORATOR_HPP__

#include <iostream>
#include <string>

#include "CommandBase.hpp"

using namespace std;

class ExecuteDecorator : public CommandBase
{
	public:
		/* Constructor */
		ExecuteDecorator() {};

		virtual int execute() = 0;	
};

#endif
