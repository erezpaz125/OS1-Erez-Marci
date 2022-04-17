#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"
//#include "kernel/proc.c"


void example_pause_system(int interval, int pause_seconds, int loop_size) {
    int n_forks = 2;
    for (int i = 0; i < n_forks; i++) {
    	fork();
    }
    for (int i = 0; i < loop_size; i++) {
        if (i % interval == 0) {
            printf("pause system %d/%d completed.\n", i, loop_size);
        }
        if (i == loop_size / 2){
            pause_system(pause_seconds);
        }
    }
    fprintf(1,"\n");
}

void example_kill_system(int interval, int loop_size) {
    int n_forks = 2;
    for (int i = 0; i < n_forks; i++) {
    	fork();
    }
    for (int i = 0; i < loop_size; i++) {
        if (i % interval == 0) {
            fprintf(1,"kill system %d/%d completed.\n", i, loop_size);
        }
        if (i == loop_size / 2){
            kill_system();
        }
    }
    fprintf(1,"\n");
}
void env(int size, int interval, char* env_name) {
    int pid;
    int result = 1;
    int loop_size = 10e6;
    int n_forks = 2;
    for (int i = 0; i < n_forks; i++) {
        pid = fork();
    }
    for(int i = 0; i < loop_size; i++) {
        if (i % loop_size / 10e0 == 0) 
        {
        	if (pid == 0) {
        		printf("%s %i/%i completed.\n", env_name, i, loop_size);
        	} else {
        		printf(" ");
        	}
        }
        if (i % interval == 0) 
        {
            result = result * size;
        }
    }
    printf("\n");
}

void env_large() {
    env(10e6, 10e6, "env_large");
}

void env_freq() {
    env(10e1, 10e1, "env_freq");
}


int main(int argc, char** argv)
{
    //example_pause_system(100,5,1000);
    //example_kill_system(100,1000);
    env_freq();
    //env_large();
    print_stats();
    exit(0);
}