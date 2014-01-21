#include "prime.h"

void* prime(void* data1){
	prime_data data = *((prime_data*)data1);	
	printf("prime %d %d", data.number, data.start);
	

	return (void*) 0;
}
