#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "ExecuteDecorator.hpp"

using namespace std;

class Input : public ExecuteDecorator
{
        private:
                CommandBase* cmd;
                string file;

        public:
                /* Constructors */
                Input(CommandBase* cmd_, string file): ExecuteDecorator() { this->cmd = cmd_; this->file = file;};

                /* Destructor */
                ~Input() { delete cmd; };

                virtual int execute()
                {
                        int new_in = open(file.c_str(), O_RDONLY);
			if(new_in < 0){
				return 1;
			}
                        int dupin = dup(0);
                        close(0);
                        dup(new_in);
                        int rtrn = this->cmd->execute();
                        close(0);
                        dup(dupin);
                        close(new_in);

                        return rtrn;
                };
};

    
#endif
