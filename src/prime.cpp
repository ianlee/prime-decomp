#include "prime.h"

void* prime(void* data1){
	long i,j, prime;
	prime_data data = *((prime_data*)data1);	
	long number = data.number;
	long start = data.start * (data.number / NUM_THREADS) ;
	long end = (data.start == NUM_THREADS -1)?data.number : (data.start + 1) * (data.number/NUM_THREADS);
	
	start = (start < 2)?2:start;
	//all numbers between start and end
	for(i=start;i<end;i++) {
        prime=1;
		// numbers that are factors of input
		if(number %i == 0) {
			//check if number is prime
			for(j=2;j<i;j++) {
				if(i%j==0) {
					prime=0;
					break;
				}
			}
			//number is prime
			if(prime==1) {
				fprintf(data.fp, "%ld ", i);
			}
		}
    }

	return (void*) 0;
}
