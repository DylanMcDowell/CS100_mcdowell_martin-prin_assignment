#ifndef _EXIT_HPP_
#define _EXIT_HPP_

#include "CommandBase.hpp"

using namespace std;

class Exit: public CommandBase{
   public:
        virtual int execute(){
		return 1;
	}
};

#endif

