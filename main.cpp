#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define OPTIONS 	"?p:t:"


int main (int argc, char **argv){
	int opt;
	int number;
	if (argc < 2){
		usage(argv);
	}
	while ((opt = getopt (argc, argv, OPTIONS))!=-1) {
		switch (opt){
			case 'p':
				number = atoi(optarg);
				createProcesses(number);
			break;
			case 't':
				number = atoi(optarg);
				createThreads(number);
			break;
			default:
			case '?':
				usage(argv);
			break;

		}
	}


	return 0;
}
int usage (char **argv){
	fprintf(stderr, "Usage: %s -[pt] [number]\n", argv[0]);
	exit(1);
}
