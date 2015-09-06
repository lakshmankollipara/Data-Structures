#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct listnode
{char entry;
 struct listnode *next;
}listnode;
typedef struct list
{int count;
 listnode *head;
}list;
void createlist(list *list)
{list->count=0;
 list->head=NULL;
}
int stackempty(list *list)
{return list->count<0;
}
int stackfull(list *list)
{return list->count>=max;
}
listnode *createstack(char item)
{listnode *nodeptr;
 if((nodeptr=(listnode*)malloc(sizeof(listnode)))==NULL)
  printf("Memory full\n");
 else {
 nodeptr->entry=item;
 nodeptr->next=NULL;
}
return nodeptr;
}
void push(char item,list *list)
{listnode *newnode;
 newnode=createstack(item);
 if(newnode==NULL)
  printf("Insertion failed\n");
 else if(stackfull(list))
  printf("cannot push as stack is full\n");
 else
{ newnode->next=list->head;
 list->head=newnode;
 list->count++;}
}
void pop(char *item,list *list)
{listnode *firstnode;
 if(list->head==NULL)
  printf("The stack is empty\n");
 else {
 firstnode=list->head;
 *item=firstnode->entry;
 list->head=firstnode->next;
 list->count--;
 free(firstnode);}
}
void display(list *list)
{
if (list->head==NULL)
printf("stack is empty\n");
else
{
listnode *curnode;
 curnode=list->head;
 while(curnode->next!=NULL)
 {
  printf("%c\n",curnode->entry);
  curnode=curnode->next;
 }
printf("%c\n",curnode->entry);
}
}
main()
{list l;
 createlist(&l);
 int n,i;
 char ch,name[10];
 printf("choose the foll. options\n1. PUSH\n2. POP\n3. DISPLAY\n");
do
{printf("enter the option u want to select\n");
 scanf("%d",&n);
 switch(n)
{case 1: printf("enter a name\n");
          scanf("%s",name);
         printf("pushing into the stack\n");
         for(i=0;name[i]!='\0';i++) 
         push(name[i],&l);
         break; 
 case 2: printf("the poped character is:\t");
         pop(&ch,&l);
         putchar(ch);
         printf("\n");
         break;
 case 3: printf("STACK CONTENTS\n");
         display(&l);
         break;
 default: printf("enter proper choice\n");
          break;          
}}while(n!=4);
}

