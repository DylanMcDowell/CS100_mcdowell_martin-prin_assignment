#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

/*this basic program will print out
 *
 *      	   Hello
 *                 World!
 *
 *         using fork() and waitpid()
 *         It will also print the child's status
 */
int main() {
        pid_t c_pid;
	pid_t returned;
        int c_status;
	
	std::cout << "Test 1: Child Returns 0\n" << std::endl;

        c_pid = fork();
        if(c_pid == 0){
                return 0;
        }
        else {
                returned = waitpid(-1, &c_status, 0);
                std::cout << "Status: " << WEXITSTATUS(c_status) << std::endl;
		std::cout << "Returned: " << returned << std::endl;
        }

	std::cout << "\nTest 2: Child returning -1\n" << std::endl;

	c_pid = fork();
        if(c_pid == 0){
                return -1;
        }
        else {
                returned = waitpid(-1, &c_status, 0);
                std::cout << "Status: " << WEXITSTATUS(c_status) << std::endl;
		std::cout << "Returned: " << returned << std::endl;
        }

	std::cout << "\nTest 3: Child returning 1\n" << std::endl;

        c_pid = fork();
        if(c_pid == 0){
                return 1;
        }
        else {
                returned = waitpid(-1, &c_status, 0);
                std::cout << "Status: " << WEXITSTATUS(c_status) << std::endl;
		std::cout << "Returned: " << returned << std::endl;
        }
}
