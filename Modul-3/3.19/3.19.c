#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
       pid_t pid = fork(); // fork a child process

    if (pid > 0) //if pid greater than 0 - parent process
{
       sleep(20); //to create zombie process we can't use wait(), but we can use sleep() systemcall
       printf("This is the parent process\n");

    }
    else if(pid == 0) //if pid equal 0 - child process
{
            printf("This is the child process\n");
            exit(0); // terminating the child (zombie) process
   }

    return 0;
}

