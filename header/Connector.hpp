#ifndef _CONNECTOR_HPP_
#define _CONNECTOR_HPP_

#include <iostream>
#include <string>

#include "CommandBase.hpp"

using namespace std;

class Connector : public CommandBase
{
	protected:
		CommandBase* left;
		CommandBase* right;

	public:
		Connector(CommandBase* l, CommandBase* r){
			left = l;
			right = r;
		}

		~Connector(){
			delete left;
			delete right;
		}

		virtual int execute() { return 0; };
};

#endif
