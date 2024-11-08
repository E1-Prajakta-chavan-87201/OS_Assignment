#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main (){

    int ret,i,s,j;

    for(i=1;i<=5;i++){
        ret=fork();

        if(ret == 0){
            for(j=1;j<=5;j++){
                printf("PID : %d , Count:%d  , Child :%d \n",getpid,j,i);
                sleep(1);
            }
            _exit(8);
        }

    }
        for(i=1;i<=5;i++){
            wait(&s);
            //printf("Exit status : %d",WEXITSTATUS(&s));
            }
    return 0;
}