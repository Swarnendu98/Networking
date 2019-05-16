#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<time.h>
#include<unistd.h>
#define SERVER "127.0.0.1"
#define PORT 8888
int main()
{
struct sockaddr_in server,client;
int s,c,cli;
char buff[100];
time_t tick;
s=socket(AF_INET,SOCK_STREAM,0);
if(s==-1)
{
printf("Socket creation failed");
}
else
{
printf("Socket created");
}
bzero(&server, sizeof(server));
server.sin_family = AF_INET;
server.sin_addr.s_addr = INADDR_ANY;
server.sin_port = htons( 8888 );
 if( bind(s,(struct sockaddr *)&server , sizeof(server)) < 0)
{
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");

 listen(s , 3);
  puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
cli = accept(s, (struct sockaddr *)&client, (socklen_t*)&c);
    if (cli < 0)
    {
        perror("accept failed");
        return 1;
    }
    puts("Connection accepted");



tick=time(NULL);
//printf("The date and time is:%s"ctime(&tick));
snprintf(buff,sizeof(buff),"%s",ctime(&tick));
printf("%s",buff);
write(s,100);
return 0;
}
