#include "thread.h"

int createThreads(int number){
	prime_data data = malloc(sizeof(prime_data));
	pthread_t* threads[NUM_THREAD];
	int i;
	timeval starttime, endtime;
	int seconds, milliseconds;
	
	data.number = number;


	gettimeofday (&starttime, NULL); //stop time
	printf("threads");
	for (i = 0; i< NUM_THREAD; i++){
		data.start = i;
		pthread_create (&(threads[i]), NULL, prime, (void*) &data);

	}
	for (i = 0; i < NUM_THREAD; i++) {
		pthread_join (threads[i], NULL);
	}
	gettimeofday (&endtime, NULL); //stop time
	seconds = endtime.tv_sec - starttime.tv_sec;
	milliseconds = endtime.tv_usec - starttime.tv_usec;
	printf ("%ds %dusec", seconds, milliseconds);
	return 0;
}

