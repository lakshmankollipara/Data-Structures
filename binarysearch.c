#include<stdio.h>
main()
{
int l=0,r,n,i,a[10],b,f=0,m=0,t,j;
printf("enter the no.of elements");
scanf("%d",&n);
printf("enter the elements");
for(i=0;i<n;i++)
{
scanf("\n %d",&a[i]);
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>a[j])
{
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
}
printf("enter the number to be searched");
scanf("%d",&b);
r=n-1;
do
{
m=(l+r)/2;
if(b==a[m])
{
f=1;
break;
}
else
{
if(b<a[m])
r=m;
else
l=m;
}
}
while(m>0);
if(f==1)
printf("\n searched number is found ");
else
printf("searched number is not found");
}

