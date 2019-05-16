#include<stdio.h>
#include<string.h>  
#include<sys/socket.h>    
#include<arpa/inet.h> 
 
int main(int argc , char *argv[])
{
    int sock,n;
    struct sockaddr_in server;
    char m[1000] , server_reply[2000];

    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );
 
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
     
    puts("Connected\n");
    if(n=read(sock,m,sizeof(m))<0)
{printf("error");
}else
printf("time %s",m);
   
    return 0;
}

