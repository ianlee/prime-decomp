#include "process.h"

int createProcesses(int number){
	prime_data data;
	pid_t childpid[NUM_THEADS] ;
	int i;
	timeval starttime, endtime;
	int seconds, milliseconds;
	
	printf("processes\n");

	data.number = number;

	gettimeofday (&starttime, NULL); //start time
	for(i= 0; i<NUM_THREADS; i++){
		if((childpid[i] = fork()) ==0){
			//is child
			data.start = i;
			prime(&data);
			exit(0);
		} elseif(childpid[i] > 0){
			//is parent
		} else {
			//error
		}
	}
	for (i = 0; i < NUM_THEADS; i++) {
		int status;
		while (-1 == waitpid(childpid[i], &status, 0));
		if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
			cerr << "Process " << i << " (pid " << pids[i] << ") failed" << endl;
			exit(1);
		}
	}

	gettimeofday (&endtime, NULL); //stop time
	seconds = endtime.tv_sec - starttime.tv_sec;
	milliseconds = endtime.tv_usec - starttime.tv_usec;
	printf ("%ds %dusec", seconds, milliseconds);
	return 0;
}

