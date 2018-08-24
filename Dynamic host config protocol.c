#include<stdio.h>
#include<string.h>
int main()
{
char ip[10][20]={"192.168.0.64","192.168.0.60","192.168.0.68","132.147.3.3"};
char et[10][20]={"1","2","3","4"};


char ipaddr[20],etaddr[20];
int i,op;
int x=0,y=0;

while(1)
{
printf("\n\n 1.DHCP 2.EXIT");
printf("\n enter the choice\n");
scanf("%d",&op);
switch(op){
case 1:
printf("enter host system\n");
scanf("%s",etaddr);
for(i=0;i<=20;i++)
{
if(strcmp(etaddr,et[i])==0)
{
printf("IP address is %s",ip[i]);
y=1;
} }
if(y==0)
printf("Host system not found in network");
y=0;
break;

case 2:
printf("Exit... \n");
return 0;
} } }
