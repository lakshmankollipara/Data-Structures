#include<stdio.h>
main()
{
int h=0,a[20],i,b,c,m=0;
printf("enter the number of elements");
scanf("%d",&b);
printf("enter the elements");
for(i=0;i<b;i++)
scanf("%d",&a[i]);
while(m<2)
{
printf("enter the number to be searched");
scanf("%d",&c);
for(i=0;i<b;i++)
{
if(a[i]==c)
{
h=0;
printf("\n %d is found at position %d",c,i+1);
break;
}
else
h++;
}
m++;
if(h!=0)
printf("\nelement is not found");
}
}
