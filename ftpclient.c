#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
FILE *fp;
int csd,n,ser,s,cli,cport,newsd;
char name[100],rcvmsg[100],rcvg[100],fname[100];
struct sockaddr_in servaddr;
printf("........ENTER THE PORT OF SERVER.........");
scanf("%d",&cport);
csd=socket(AF_INET,SOCK_STREAM,0);
if(csd<0)
{
printf("Error....\n");
exit(0);
}
else
printf("******SOCKET CREATED SUCESSFULLY******\n");
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(cport);
if(connect(csd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0)
printf("Error in connection\n");
else
printf("..........CONNECTED TO THE SERVER..........\n");
printf("******ENTER THE FILENAME YOU WANT ?!*******\t");
scanf("%s",name);
printf("...........ENTER THE NEW NAME FOR FILE........\t");
scanf("%s",fname);
fp=fopen(fname,"w");
send(csd,name,sizeof(name),0);
while(1)
{
s=recv(csd,rcvg,100,0);
rcvg[s]='\0';
if(strcmp(rcvg,"error")==0)
printf("File is not available\n");
exit(0);
if(strcmp(rcvg,"completed")==0)
{
printf("*****........FILE IS TRANSFERED SUCESSFULLY........*****\n");
printf("...client exit...");
fclose(fp);
close(csd);
break;
}
else
fputs(rcvg,stdout);
fprintf(fp,"%s",rcvg);
}
}

