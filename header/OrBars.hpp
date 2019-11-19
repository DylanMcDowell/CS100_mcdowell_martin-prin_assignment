#ifndef _ORBARS_HPP_
#define _ORBARS_HPP_

#include <iostream>
#include <string>

#include "Connector.hpp"

using namespace std;

class OrBars : public Connector
{
	private:
		vector<CommandBase*> cmd;
		int rtrn = 0;
		int result;

	public:
		int execute()
		{
		
			result = cmd.at(0)->execute();

			if(result == -1){
				rtrn -1;
			}
			else if(result == 0)
			{
				result = cmd.at(1)->execute();
				if(result == -1)
				{
					rtrn = -1;
				}
				else if(result == 0)
				{
					rtrn = 0;
				}
				else
				{
					rtrn = 1;
				}
			}
			else
			{
				rtrn = 1;
			}

			return rtrn;
		}
};

#endif
