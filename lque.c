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
int queempty(list *list)
{return list->count<0;
}
int quefull(list *list)
{return list->count>=max;
}
listnode *createque(char item)
{listnode *nodeptr;
 if((nodeptr=(listnode*)malloc(sizeof(listnode)))==NULL)
  printf("Memory full\n");
 else {
 nodeptr->entry=item;
 nodeptr->next=NULL;
}
return nodeptr;
}
void append(char item,list *list)
{listnode *newnode,*curnode;
 newnode=createque(item);
 if(newnode==NULL)
  printf("Insertion failed\n");
 else {if(quefull(list))
  printf("Q is full\n");
else{ if(list->head==NULL)
  { list->head=newnode;list->count++;}
 else
 { curnode=list->head;
  while(curnode->next!=NULL)
  {curnode=curnode->next;
   curnode->next=newnode;
  }
 list->count++;}
}}}
void serve(char *item,list *list)
{listnode *firstnode;
 if(list->head==NULL)
  printf("Q is empty\n");
else {
 firstnode=list->head;
 *item=firstnode->entry;
 list->head=firstnode->next;
 list->count--;
 free(firstnode);}
}
void display(list *list)
{listnode *curnode;
 if(queempty(list))
 printf("Q is empty\n");
else{  curnode=list->head;
 printf("%c\n",curnode->entry);
 while(curnode->next!=NULL)
 {curnode=curnode->next;
  printf("%c\n",curnode->entry);
}list->count++;
}}
main()
{list l;
 createlist(&l);
 int n,i;
 char ch,name[10];
 printf("choose the foll. options\n1. APPEND\n2. SERVE\n3. DISPLAY\n");
do
{printf("enter the option u want to select\n");
 scanf("%d",&n);
 switch(n)
{case 1: printf("enter a name\n");
         scanf("%s",name);
         printf("Appending into Queue\n");
         for(i=0;name[i]!='\0';i++)
         append(name[i],&l);
         break;
 case 2: printf("Served element in the Queue:\t");
         serve(&ch,&l);
         putchar(ch);
         printf("\n");
         break;
 case 3: printf("QUEUE CONTENTS\n");
         display(&l);
         break;
 default: printf("enter proper choice\n");
          break;
}}while(n!=4);
}

