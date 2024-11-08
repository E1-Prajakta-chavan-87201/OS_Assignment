#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
    int ret ,i,pid1,s1,pid2,s2,pid3,s3;
    pid1=fork();//child 1
    if(pid1 == 0){
        pid2=fork();
        if(pid2==0){

            pid3=fork();
            if(pid3==0){
                for(i=1;i<=5;i++){
                    printf("Child 3 :%d\n",i);
                    sleep(1);
                }
                _exit(0);
            }
            else{
            for(i=1;i<=5;i++){
                printf("Child 2 :%d\n ",i);
                sleep(1);
            }
            waitpid(pid3,&s3,0);
            _exit(0);
        }
        }
        else{
        
        for(i=1;i<=5;i++){
            printf("Child 1 :%d\n",i);
            sleep(1);
        }
        waitpid(pid2,&s2,0);
        _exit(0);
    }
    }

    else{
        for(i=1;i<=5;i++){
            printf("Parent :%d\n",i);
            sleep(1);
        }

        waitpid(pid1,&s1,0);
    }



    return 0;
}