#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

int const MAX_ARGS = 5;

int main(){

	int result;
	char* args[] = {"echo","Hello World!", '\0'};

	result = execvp(args[0], args);
	std::cout << "\nStatus: " << result << std::endl;//Note: this should not run. execvp() exits when finished.
}
