#include "../header/Command.hpp"
#include <unistd.h>
#include <sys/wait.t>

int Command::execute(){
	int result
	int fork_ret
	int c_status

	fork_ret = fork();
	if(fork_ret == -1){
		return -1;
	}
	else if(fork_ret == 0){
		execvp(cmd_args[0], cmd_args);
	}
	else{
		result = waitpid(-1, &c_status, 0);
		
	}
	return result;
}
