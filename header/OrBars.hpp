#ifndef _ORBARS_HPP_
#define _ORBARS_HPP_

#include <iostream>
#include <string>

#include "Connector.hpp"

using namespace std;

class OrBars : public Connector {
	public:

		OrBars(CommandBase* left, CommandBase* right): Connector(left,right) {}

		int execute()
		{
		
			int result = left->execute();
			int rtrn = 0; 
			if(result == -1){
				rtrn -1;
			}
			else if(result == 1)
			{
				result = right->execute();
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
				rtrn = 0;
			}

			return rtrn;
		}
};

#endif
