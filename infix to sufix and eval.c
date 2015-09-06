#include<stdio.h>
#include<string.h>
#define maxsize 10
typedef char stackentry;
typedef int stackentry1;
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
typedef struct stack1
{
int top;
stackentry1 entry[maxsize];
}stack1;
int full(stack *s)
{
return s->top>=maxsize;
}
int empty(stack *s)
{
return s->top<=0;
}
int create(stack1 *s)
{
s->top=0;
}
void put(stackentry1 item,stack1 *s)
{
if(full(s))
{
printf("stack full\n");
}
else
{
s->entry[s->top++]=item;
}
}
void get(stackentry1 *item,stack1 *s)
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
int precedence(char ch)
{
if((ch=='*')||(ch=='/'))
{
return 2;
}
else if((ch=='+')||(ch=='-'))
{
return 1;
}
else if((ch>='a')&&(ch<='z'))
{
return 3;
}
else if((ch=='\0'))
{
return 0;
}
}
int suffix(char *exp)
{
stack1 s;
create(&s);
int i=0,r,value,j,k;
while(exp[i]!='\0')
{
if(exp[i]<='z'&&exp[i]>='a')
{
printf("enter the value of %c :",exp[i]);
scanf("%d",&value);
put(value,&s);
}
else
{
get(&j,&s);
get(&k,&s);
switch(exp[i])
{
case'+':put(k+j,&s);
break;
case'-':put(k-j,&s);
break;
case'*':put(k*j,&s);
break;
case'/':put(k/j,&s);
break;
}
}
i++;
}
get(&r,&s);
return (r);
}
char top(stack *s)
{
return (s->entry[(s->top-1)]);
}
int main()
{
stack s;
char ip[10],op[10],ch;
int i=0,j=0,r;
printf("enter the infix expression to convert into suffix:\n");
scanf("%s",&ip);
createstack(&s);
push('\0',&s);
while(ip[i]!='\0')
{
while((precedence(ip[i]))<=(precedence(top(&s))))
{
pop(&ch,&s);
op[j++]=ch;
}
printf("the suffix expression is %s\n",op);
r=suffix(op);
printf("the value of expression is %d\n",r);
return 0;
}
