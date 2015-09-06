#include<stdio.h>
#include<string.h>
#define max 10
typedef char ent;
typedef int ent1; 
typedef struct stack
{int top;
 ent entry[max];
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
void push(ent item,stack *s)
{if (StackFull(s))
  printf("Stack is Full\n");
 else s->entry[s->top++]=item;
}
void pop(ent *item,stack *s)
{if(StackEmpty(s))
  printf("Stack is Empty\n");
 else {*item=s->entry[--(s->top)];
      }
}

typedef struct stack1
{int top;
 ent1 entry[max];
}stack1;
int Full(stack1 *s)
{return s->top>=max;
 }
int Empty(stack1 *s)
{return s->top<=0;
 }
void create(stack1 *s)
{s->top=0;
 }
void psh(ent1 item,stack1 *s)
{if (Full(s))
  printf("Stack is Full\n");
 else s->entry[s->top++]=item;
}
void pp(ent1 *item,stack1 *s)
{if(Empty(s))
  printf("Stack is Empty\n");
 else {*item=s->entry[--(s->top)];
      }
}


int suffix_eval(char *op)
{stack1 s;
 create(&s);
 int i=0,value,j,k,r;
 while(op[i]!='\0')
 {if((op[i]>='a')&&(op[i]<='z'))
  {printf("enter the value of %c: ",op[i]);
   scanf("%d",&value);
   psh(value,&s);
  }
 else 
  {pp(&j,&s);
   pp(&k,&s);
   switch(op[i])
   {case '+':psh(j+k,&s);
             break;
    case '-':psh(k-j,&s);
             break;
    case '*':psh(k*j,&s);
             break;
    case '/':psh(k/j,&s);
             break;
    default:printf("please enter proper suffix expression\n");
            break;
   }
  }
  i++;
 }
 pp(&r,&s);
 return(r);
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
 int i=0,j=0,r;
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
r=suffix_eval(op);
printf("the final value is %d\n",r);
}
