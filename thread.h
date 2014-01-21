#ifndef THREADS
#define THREADS

#define NUM_THREAD 5
#include "prime.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int createThreads(int number);

#endif
