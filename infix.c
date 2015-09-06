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
int pre(char ch)
{if((ch=='+')||(ch=='-'))
 {return 1;}
 else if((ch=='*')||(ch=='/'))
 {return 2;}
 else if((ch>='a')&&(ch<='z'))
 {return 3;}
 else if(ch=='\0')
 {return 0;}
}
char top(stack *s)
{return s->entry[s->top-1];
}
main()
{stack s;
 char inp[20],op[20],ch;
 int i=0,j=0;
 printf("enter the infix expression\n");
 scanf("%s",inp);
 createstack(&s);
 push('\0',&s);
 while(inp[i]!='\0')
 {while((pre(inp[i]))<=pre(top(&s)))
  {pop(&ch,&s);
   op[j++]=ch;
   }
 push(inp[i],&s);
 i++;
}
while(!StackEmpty(&s))
 {pop(&ch,&s);
  op[j++]=ch;
  }
printf("the suffix expression is\n");
printf("%s\n",op);
 
 
}

