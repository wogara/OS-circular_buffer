#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]) {
    int * buffer = mmap(NULL, 12*sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0); 
    int * in = buffer;
    int * out = buffer;
    char *p;
    long nconv = strtol(argv[1],&p,10);
    int n = nconv;
    long dconv = strtol(argv[2],&p,10);
    int d = dconv;
    out = out + 11;
    in = in + 10;
    pid_t child;
    child = fork();
    if(child==0){
        srand (time(NULL));

        int k = 0;
        int next_produced = k*d;
        double wait;
        for (int i = 0; i < n; i++){
                while((*in + 1)%10 == *out){
                }
                wait = (rand() / (RAND_MAX / 9.999)); 
                sleep(wait);
                buffer[*in] = next_produced;
                *in = (*in + 1)%10;
                k = k + 1;
                next_produced = k*d;
                fflush(stdout);
        }
        exit(0);
    }else{
        int next_consumed;
        while(1) {
                while (*in == *out){
                }
                next_consumed = buffer[*out];
                printf("%d\n", next_consumed);
                *out = (*out + 1)%10;
                fflush(stdout);
    
        }
    }
    return 0;
}
