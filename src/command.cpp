#include "../header/Command.hpp"
#include <unistd.h>
#include <sys/wait.t>

int Command::execute(){
	int result
	int fork_ret
	int c_status
	int exe_res

	fork_ret = fork();
	if(fork_ret == -1){
		return -1;
	}
	else if(fork_ret == 0){
		exe_res = execvp(cmd_args[0], cmd_args);
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
