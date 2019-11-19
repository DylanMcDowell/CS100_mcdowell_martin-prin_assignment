#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

int const MAX_ARGS = 5;

int main(){
	pid_t process;
        int result;
	int c_status;
        char* args[] = {"echo","Hello World!", '\0'};
	process = fork();
	if(process == 0){
        	result = execvp(args[0], args);
		return -1;
	}
	else{
		result = waitpid(-1, &c_status, 0);
                std::cout << "Status: " << WEXITSTATUS(c_status) << std::endl;
		std::cout << "Returned: " << result << std::endl;
	}

	std::cout << std::endl;
	char* args2[] = {"ech", "Hello World", '\0'};
	process = fork();
        if(process == 0){
                result = execvp(args2[0], args2);
		return result;
        }
        else{
                result = waitpid(-1, &c_status, 0);
                std::cout << "Status: " << WEXITSTATUS(c_status) << std::endl;
                std::cout << "Returned: " << result << std::endl;
        }
}
