#include<stdio.h>
#include<string.h>
#define maxsize 10
typedef int stackentry;
typedef struct stack
{
int top;
stackentry entry[maxsize];
}stack;
int stackfull(stack *s)
{
return s->top>=maxsize;
}
int stackempty(stack *s)
{
return s->top<=0;
}
int createstack(stack *s)
{
s->top=0;
}
void push(stackentry item,stack *s)
{
if(stackfull(s))
{
printf("stack full\n");
}
else
{
s->entry[s->top++]=item;
}
}
void pop(stackentry *item,stack *s)
{
if(stackempty(s))
{
printf("stack is empty");
}
else
{
*item=s->entry[--(s->top)];
}
}
int top(stack *s)
{
return (s->entry[(s->top-1)]);
}
int suffix(char *exp)
{
stack s;
createstack(&s);
int i=0,r,value,j,k;
while(exp[i]!='\0')
{
if(exp[i]<='z'&&exp[i]>='a')
{
printf("enter the value of %c :",exp[i]);
scanf("%d",&value);
push(value,&s);
}
else
{
pop(&j,&s);
pop(&k,&s);
switch(exp[i])
{
case'+':push(k+j,&s);
break;
case'-':push(k-j,&s);
break;
case'*':push(k*j,&s);
break;
case'/':push(k/j,&s);
break;
}
}
i++;
}
pop(&r,&s);
return (r);
}
int main()
{
char exp[10];
int r;
printf("enter the suffix expression:\n");
scanf("%s",&exp);
r=suffix(exp);
printf("the value of expression is %d\n",r);
return 0;
}

