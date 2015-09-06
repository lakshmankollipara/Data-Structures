#include<stdio.h>
main()
{
int i,j,t;
int a[10];
printf("\n enter integer values in the form of array");
for(i=0;i<=9;i++)
{
scanf("%d",&a[i]);
}
printf("the given values in the array are");
for(i=0;i<=9;i++)
{
printf("%d\t",a[i]);
}
for(i=0;i<=9;i++)
{
for(j=i+1;j<=9;j++)
{
if(a[i]>a[j])
{
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
}
printf("the sorted array is");
for(i=0;i<=9;i++)
{
printf("%d\t",a[i]);
}
}
