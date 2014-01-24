#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define OPTIONS 	"?p:t:"


int main (int argc, char **argv){
	int opt;
	long number;
	int type;
	if (argc < 2){
		usage(argv);
	}
	while ((opt = getopt (argc, argv, OPTIONS))!=-1) {
		switch (opt){
			case 'p':
				number = atol(optarg);
				type = 1;
			break;
			case 't':
				number = atol(optarg);
				type = 2;

			break;
			default:
			case '?':
				usage(argv);
			break;

		}
	}
	

	if (type ==1){
		createProcesses(number);		
	} else if(type == 2){
		createThreads(number);
	}


	return 0;
}
int usage (char **argv){
	fprintf(stderr, "Usage: %s -[pt] [number]\n", argv[0]);
	exit(1);
}
