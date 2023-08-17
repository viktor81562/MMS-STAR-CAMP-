
#include <stdio.h>
#include <stdlib.h>
#include<inttypes.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int sum_digits(uint64_t number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s file1 file2 ... fileN\n", argv[0]);
        return 1;
    }



    uint64_t total_sum = 0;


 int pid;
    int fd[2];
        if(pipe(fd) < 0){
            perror("problem with pipe");
            exit(-1);
        }
           
    for (int i = 1; i < argc; i++) {
        

        

        pid = fork();

        
        if(pid == -1){
            perror("Problem!");
            exit(-1);
        }
        if(pid == 0){

        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            perror(argv[i]);
            continue;
        }

        uint64_t number;
        while (fread(&number, sizeof(number), 1, file) == 1) {
            total_sum += sum_digits(number);
        }
        
        write(fd[1],&total_sum,sizeof(total_sum));
        close(fd[1]);

        fclose(file);
            return 0;
        }
    }
    close(fd[1]);
    uint64_t a = 0;
    for(int i = 1; i < argc; i++){
        wait(NULL);
        uint64_t temp;
        read(fd[0],&temp,sizeof(temp));
        a = temp + a;

    }

    printf("Total sum of digits - %lu\n", a);

    return 0;
}