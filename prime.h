#ifndef PRIME
#define PRIME

#include <stdio.h>
#define NUM_THREADS 5


void* prime(void * data1);
int decompose(long number);



struct prime_data {
	long number;
	long start;

};
#endif
