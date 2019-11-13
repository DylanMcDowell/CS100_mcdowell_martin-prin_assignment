#include "../header/Command.hpp"
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

int Command::execute(){
        int result;
        int fork_ret;
        int c_status;
        int exe_res;

        char* cmd_array[cmd_args.size()];
        for(int i = 0; i < cmd_args.size(); i++){
		strcpy(cmd_array[i], cmd_args.at(i).c_str());
        }

        fork_ret = fork();
        if(fork_ret == -1){
                return -1;
        }
        else if(fork_ret == 0){
                exe_res = execvp(cmd_array[0], cmd_array);
                return exe_res;
        }
        else{
                result = waitpid(-1, &c_status, 0);
        }

        if(result == 255){//this only ever happens if the resulting return is negative. i.e. it failed.
                result = -1;
        }

        return result;
}

