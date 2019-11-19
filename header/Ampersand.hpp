#ifndef _AMPERSAND_HPP_
#define _AMPERSAND_HPP_

#include <iostream>
#include <string>

#include "Connector.hpp"

using namespace std;

class Ampersand : public Connector
{
	private:
		vector<CommandBase*> cmd;
		int rtrn = 0;

	public:
		int execute()
		{
			
			if(cmd.at(0)->execute() == 0)
			{			

				if(cmd.at(1)->execute() != 0)
				{
					rtrn = 1;
				}
			}
			else
			{
				rtrn = 1;
			}

			return rtrn;

		};
}; 

#endif
