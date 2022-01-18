/*iFork.c*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
   int pid = fork();

   if (pid == 0) {
        printf("Hello from the child. PID -> %u : PPID -> %d\n", getpid(), getppid());
    } else {
       printf("Hello from the parent. PID -> %u\n", getpid());
       wait(NULL);
    }

    return 0;
}  
