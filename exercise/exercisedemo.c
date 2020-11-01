#include<stdio.h>
#include<unistd.h>
int main(int argc, char const *argv[])
{
    unsigned char rbuff[128];
    int n1,n2;
    pid_t id;
    int pfd1[2];
    int pfd2[2];

    pipe(pfd1);
    pipe(pfd2);
    id = fork();
    printf("enter two numbers:\n");
    scanf("%d%d",&n1,&n2);
    printf("*********** \n");

    if(0==id)
    {//child process
    int sum;
    printf("you are in 2nd process\n");
    printf("process2 received 1st num:%d \n",n1);
    printf("process2 received 2nd num:%d \n",n2);
    sum= n1 + n2;

    printf("process2 send sum to process1:%d",sum);


    read(pfd1[0],rbuff,128);
    printf("values :%d%d\n",rbuff);
    close(pfd1[0]);
    }
    else
    {//parent process
    printf("you are in 1st process\n");
    printf("process1 sent 1st num to process2:%d \n",n1);
    printf("process1 sent 2st num to process2:%d \n",n2);
    printf("**********\n");

    write(pfd1[1],(n1,n2),5);
    close(pfd1[1]);
        
    }
    
    return 0;
}
