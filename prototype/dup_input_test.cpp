#include <stdlib.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <fcntl.h>
#include <sys/wait.h> 
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int newin = open("duptest.txt", O_RDWR);

	if(newin < 0){
		cout << "AAAAAAAAAAAAAAAAAAH" << endl;
		return 1;
	}	

	int dupin = dup(0);

	//close(0);

	//dup(newin);

	dup2(newin, 0);

	char* args[] = {"echo", NULL};

	int exe_res;
	int result;

	int fork_ret = fork();

	if(fork_ret == -1){
		return -1;
	}
	else if(fork_ret == 0){
		exe_res = execvp(args[0], args);
		exit(exe_res);
	}
	else{
		waitpid(-1, &result, 0);
	}

	cout << result << endl;

	close(0);

        dup(dupin);

	return 0;
}
