#include<stdio.h>
#include<string.h>
struct stud
{
int reg_no;
char name[8];
}s[5];
main()
{
struct stud t;
int i,j;
char a[20],b[20];
int f=0;
printf("\n enter the data for each stud");
for(i=0;i<5;i++)
{
printf("\n enter the reg no");
scanf("%d",&s[i].reg_no);
printf("\n enter the name");
scanf("%s",s[i].name);
}
for(i=0;i<5;i++)
{
printf("\n%d",s[i].reg_no);
printf("\t%s",s[i].name);
}
printf("\n");
printf("\n enter a name to search");
scanf("%s",a);
for(i=0;i<5;i++)
{
if(strcmp(a,s[i].name)==0)
{
f=1;
printf("\n the name is found");
break;
}
}
if(f==0)
printf("name not in the array");
printf("\n sorting reg numbers");
for(i=0;i<5;i++)
{
for(j=i+1;j<5;j++)
{
if(s[i].reg_no>s[j].reg_no)
{
t=s[i];
s[i]=s[j];
s[j]=t;
}
}
}
printf("\n sorted record");
for(i=0;i<5;i++)
{
printf("\n%d",s[i].reg_no);
printf("\t%s",s[i].name);
}
printf("\n");
}
