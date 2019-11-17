#ifndef _SEMICOLON_HPP_
#define _SEMICOLON_HPP

#include <iostream>
#include <string>

#include "Connector.hpp"

using namespace std;

class SemiColon: public Connector
{
	private:
		vector<CommandBase*> cmd;
		int rtrn = 0;

	public:
		int execute()
		{
			cmd.at(0)->execute();
			cmd.at(1)->execute();

			if(cmd.at(0)->execute != 0 || cmd.at(1)->execute() != 0)
			{
				rtrn = -1;
			}

			return rtrn;
		};
};

#endif
