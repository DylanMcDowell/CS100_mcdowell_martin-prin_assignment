#ifndef _SEMICOLON_HPP_
#define _SEMICOLON_HPP

#include <iostream>
#include <string>

#include "Connector.hpp"

using namespace std;

class SemiColon: public Connector
{
	public:

		SemiColon(CommandBase* l, CommandBase* r): Connector(l, r) {}

		virtual int execute()
		{

			int result1 = cmd.at(0)->execute();
			int result2;
			int rtrn = 0;

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
				else if (result2 == 1)
				{
					rtrn = 1;
				}
			}

			return rtrn;
		};
};

#endif
