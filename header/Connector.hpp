#ifndef _CONNECTOR_HPP_
#define _CONNECTOR_HPP_

#include <iostream>
#include <string>

#include "CommandBase.hpp"

using namespace std;

class Connector : public CommandBase
{
	private:
		vector<CommandBase*> cmd;

	public:
		virtual int execute() { return 0; };
};

#endif
