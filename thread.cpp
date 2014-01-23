#include "thread.h"

int createThreads(long number){
	prime_data data[NUM_THREADS];

	pthread_t threads[NUM_THREADS];
	int i;
	timeval starttime, endtime;
	int seconds, milliseconds;
	





	gettimeofday (&starttime, NULL); //stop time
	printf("threads");
	for (i = 0; i< NUM_THREADS; i++){

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
	printf ("%ds %dusec", seconds, milliseconds);

	return 0;
}

