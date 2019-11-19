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
		int result1 = 0;
		int result2 = 0;

	public:
		virtual int execute()
		{
			result1 = cmd.at(0)->execute();

			if(result1 == -1)
			{
				rtrn = -1;
			}
			else
			{
				result2 = cmad.at(1)->execute();
				
				if (result2 == -1)
				{
					rtrn = -1;
				}
				else if (result1 == 1 || result2 == 1)
				{
					rtrn = 1;
				}
			}

			return rtrn;
		};
};

#endif
