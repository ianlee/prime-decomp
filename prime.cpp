#include "prime.h"

void* prime(void* data1){
	prime_data data = *((prime_data*)data1);	
	printf("prime %d %d", data.number, data.start);
	
	int start = data.start * (data.number / NUM_THREADS) ;
	int end = (data.start == NUM_THREADS)?data.number : (data.start + 1) * (data.number/NUM_THREADS) -1;
	for(i=start;i<=end;i++) {
        prime=1;
        for(j=2;j<i;j++) {
            if(i%j==0) {
                prime=0;
                break;
            }
        }

        if(prime==1) {
            cout<<i<<", ";
		}
    }

	return (void*) 0;
}
