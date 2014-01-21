#include "thread.h"

int createThreads(int number){
	prime_data data;
	pthread_t threads;
	int i;

	data.number = number;



	printf("threads");
	for (i = 0; i< NUM_THREAD; i++){
		data.start = i;
		pthread_create (&threads, NULL, prime, (void*) &data);

	}

	return 0;
}

