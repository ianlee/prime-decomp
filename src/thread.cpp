#include "thread.h"

int createThreads(long number){
	prime_data data[NUM_THREADS];

	pthread_t threads[NUM_THREADS];
	int i;
	timeval starttime, endtime;
	int seconds, milliseconds;
	FILE* fp = fopen("thread.txt", "a");
	FILE* fp2= fopen("primes.txt", "a");	





	gettimeofday (&starttime, NULL); //stop time

	for (i = 0; i< NUM_THREADS; i++){
		(data[i]).fp = fp2;
		(data[i]).start = i;
		(data[i]).number = number;
		pthread_create (&(threads[i]), NULL, prime, (void*) &(data[i]));

	}
	for (i = 0; i < NUM_THREADS; i++) {
		pthread_join (threads[i], NULL);
	}
	gettimeofday (&endtime, NULL); //stop time
	seconds = endtime.tv_sec - starttime.tv_sec;
	milliseconds = endtime.tv_usec - starttime.tv_usec;
	fprintf (fp, "%ds %dusec\n", seconds, milliseconds);

	fclose(fp);
	fclose(fp2);
	return 0;
}

