#ifndef PRIME
#define PRIME

#include <stdio.h>
#define NUM_THREADS 5


void* prime(void * data1);
int decompose(int number);



struct prime_data {
	int number;
	int start;

};
#endif
