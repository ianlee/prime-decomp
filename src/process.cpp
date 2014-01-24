#include "process.h"

int createProcesses(long number){
	prime_data data;
	pid_t childpid[NUM_THREADS] ;
	int i;
	timeval starttime, endtime;
	int seconds, milliseconds;
	FILE* fp = fopen("process.txt", "a");
	data.fp = fopen("primes.txt", "a");
	
	fprintf (fp, "%ld\t", number);
	fprintf (data.fp, "%ld\t", number);
	fflush(fp);
	fflush(data.fp);

	data.number = number;

	gettimeofday (&starttime, NULL); //start time
	for(i= 0; i<NUM_THREADS; i++){
		if((childpid[i] = fork()) ==0){
			//is child
			data.start = i;
			prime(&data);
			exit(0);
		} else if(childpid[i] > 0){
			//is parent
		} else {
			//error
		}
	}
	for (i = 0; i < NUM_THREADS; i++) {
		int status;
		while (-1 == waitpid(childpid[i], &status, 0));
		if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
			printf("Process %d (pid %d ) failed \n", i, childpid[i]);
			exit(1);
		}
	}

	gettimeofday (&endtime, NULL); //stop time
	seconds = endtime.tv_sec - starttime.tv_sec;
	milliseconds = endtime.tv_usec - starttime.tv_usec;
	fprintf (fp, "%ds %dusec\n", seconds, milliseconds);
	fprintf (data.fp, "\n");
	fclose(fp);
	fclose(data.fp);
	return 0;
}

