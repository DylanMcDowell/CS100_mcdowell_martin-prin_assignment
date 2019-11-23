#ifndef _AMPERSAND_HPP_
#define _AMPERSAND_HPP_

#include <iostream>
#include <string>

#include "Connector.hpp"

using namespace std;

class Ampersand : public Connector
{
	public:

		Ampersand(CommandBase* l, CommandBase* r): Connector(l, r){}

		virtual int execute()
		{
			int result = left->execute();
			int rtrn = 0;
			if(result == -1){
				rtrn = -1;
			}
			else if(result == 0)
			{			
				result = right->execute();
				if(result == -1)
				{
					rtrn = -1;
				}
				else if(result == 1){
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
