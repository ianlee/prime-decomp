#include "process.h"

int createProcesses(int number){
	prime_data data;
	pid_t childpid = 0;
	int i;
	printf("processes\n");

	data.number = number;


	for(i= 0; i<NUM_PROCESS; i++){
		if((childpid = fork()) >0){
			data.start = i;
			prime(&data);
			break;
		}
	}

	return 0;
}

