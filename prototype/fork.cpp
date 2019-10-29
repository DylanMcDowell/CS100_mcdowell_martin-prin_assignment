#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

/*this basic program will print out

	Hello 
	World!

using fork() and waitpid()
It will also print the child's status*/
int main() {
	int c_pid;
	int c_status;

	c_pid = fork();
	if(c_pid == 0){
		std::cout << "Hello " << std::endl;
		return 1;
	}
	else {
		waitpid(0, &c_status, 0);
		std::cout << "World!" << std::endl;
		std::cout << c_status << std::endl;

	}
}
