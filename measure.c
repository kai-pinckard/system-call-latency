#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

/*
This program attempts to measure the amount of time a syscall takes.
*/
int main(){

    int ITERATIONS = 1000000;
    char buffer[1];
    struct timeval initial_time = {0, 0};
    struct timeval current_time = {0, 0};

    gettimeofday(&initial_time, NULL);
    for (int i = 0; i < ITERATIONS; i++)
    {
        // 0 is the file descriptor for stdin
        read(0, buffer, 0);
    }
    gettimeofday(&current_time, NULL);

    double elapsed_time = current_time.tv_usec - initial_time.tv_usec;
    double average_time  = elapsed_time / ITERATIONS;
    printf("Average time (microseconds): %lf\n", average_time);

    return 0;
}
