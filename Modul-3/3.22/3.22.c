#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
int main() {
	pid_t child_pid, wpid;
        int status = 0;
        int i = 1;

	const char *name = "OS";
	int shm_fd;
    	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	ftruncate(shm_fd, 4096);
	void *ptr;

    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    for (int id=0; id<i; id++) {
    if ((child_pid = fork()) == 0) {

    while(num !=1 && num>0) {
        if (num%2 == 0){
            num = num/2;
            //printf("%d\n",num);
	    printf("%d\n",num, ptr);
        }
        else{
            num = 3*num+1;
            printf("%d\n", num, ptr);
        }
    }
    }
}
while ((wpid = wait(&status)) > 0);
exit(0);
shm_unlink(name);
}
