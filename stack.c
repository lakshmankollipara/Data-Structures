#include<stdio.h>
#include<string.h>
#define maxsize 10
typedef char stackentry;
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
int main()
{
stack s;
char ch,name[10];
int i;
createstack(&s);
printf("enter a string\n");
scanf("%s",&name);
for(i=0;name[i]!='\0';i++)
{
push(name[i],&s);
}
while(!stackempty(&s))
{
pop(&ch,&s);
putchar(ch);
}
printf("\n");
return 0;
}
