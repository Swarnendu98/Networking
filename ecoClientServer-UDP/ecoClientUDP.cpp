#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#define SERVER "127.0.0.1"
#define BUFLEN 512
#define PORT 8080
void die(char *s)
{
perror(s);
exit(1);
}
int main(void)
{
struct sockaddr_in si_other;
int s,i,slen=sizeof(si_other);
char buf[BUFLEN];
char message[BUFLEN];
if((s=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP))==-1)
{
die("socket");
}
else
printf("Socket created\n");
memset((char *) &si_other,0,sizeof(si_other));
si_other.sin_family=AF_INET;
si_other.sin_port=htons(PORT);
if(inet_aton(SERVER, &si_other.sin_addr)==0)
{
fprintf(stderr,"inrt_aton() failed\n");
exit(1);
}
while(1)
{
printf("enter message:");
gets(message);
if(sendto(s,message,strlen(message),0,(struct sockaddr *) &si_other,slen)==-1)
{
die("sendto()");
}
memset(buf,'\0',BUFLEN);
if(recvfrom(s,buf,BUFLEN,0,(struct sockaddr *) &si_other,&slen)==-1)
{
die("recvfrom()");
}
puts(buf);
}
close(s);
return 0;
}
