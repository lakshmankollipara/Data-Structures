#include<stdio.h>
#include<string.h>
#define max 10
typedef struct stack
{int top;
 char entry[max];
}stack; 
int StackFull(stack *s)
{return s->top>=max;
 }
int StackEmpty(stack *s)
{return s->top<=0;
 }
void createstack(stack *s)
{s->top=0;
}
void push(char item,stack *s)
{if (StackFull(s))
  printf("Stack is Full\n");
 else s->entry[s->top++]=item;
}
void pop(char *item,stack *s)
{if(StackEmpty(s))
  printf("Stack is Empty\n");
 else {*item=s->entry[--(s->top)];
      }
}
main()
{stack s;
 char ch,name[10];
 int i;
 createstack(&s);
 printf("enter a string\n");
 scanf("%s",name);
 for(i=0;name[i]!='\0';i++)
{ push(name[i],&s);}
 while(!StackEmpty(&s))
 {pop(&ch,&s);
  putchar(ch);
  if(strcmp(ch,name)==0)
  printf("it is a pallindrome\n");
  else printf("it is not pallindrome\n");
 }
 printf("\n");
}
