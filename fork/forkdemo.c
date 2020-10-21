

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc, char const *argv[])
{
    pid_t id;
    printf("before fork \n");
    id= fork();
    
    if(0==id)
    {
        printf("In child :PID = %d\t PPID= %d\n", getpid(),getppid());

    }
    else
    {
        
         printf("In parent :PID = %d\t PPID= %d\n", getpid(),getppid());
    }
    
    return 0;
}
