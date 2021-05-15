#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main() {

    pid_t child_pid, wpid;
    int status = 0;
    int i = 1;
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    for (int id=0; id<i; id++) {
    if ((child_pid = fork()) == 0) {

    while(num !=1 && num>0) {
        if (num%2 == 0){
            num = num/2;
            printf("%d\n",num);
        }
        else{
            num = 3*num+1;
            printf("%d\n", num);
        }
    }
	exit(0);
    }
    }
while ((wpid = wait(&status)) > 0);
exit(0);
}
