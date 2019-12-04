#include "../header/Command.hpp"
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <iostream>

int Command::execute(){
        int result;
        int fork_ret;
        int exe_res;
	int i;

        char* cmd_array[cmd_args.size()+1];

	for(i = 0; i < cmd_args.size(); i++){
                cmd_array[i] = new char;
                strcpy(cmd_array[i], cmd_args.at(i).c_str());
        }

	fork_ret = fork();

        if(fork_ret == -1){
                return -1;
	}
        else if(fork_ret == 0){
		cmd_array[i] = NULL;

                exe_res = execvp(cmd_array[0], cmd_array);

		if(-1 == exe_res){ perror("Error ");}

                exit(exe_res);
        }
        else{
                waitpid(-1, &result, 0);
        }

        if(result != 0){//this only ever happens if the resulting return is negative. i.e. it failed.
                result = 1;
	}

	for(i = 0; i < cmd_args.size(); i++){
                delete cmd_array[i];
        }

        return result;
}

