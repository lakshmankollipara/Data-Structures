#include<stdio.h>
struct node
{
struct node *prev;
int d;
struct node *next;
}*list=NULL,*head=NULL;
typedef struct node l;
void insertfornt(int a)
{
l *temp;
if(list==NULL)
{
list=(l*)malloc(sizeof(l));
list->d=a;
list->prev=list->next=NULL;
}
else
{
temp=(l*)malloc(sizeof(l));
temp->d=a;
temp->prev=NULL;
temp->next=list;
list->prev=temp;
list=temp;
}
}
void deletefront()
{
l *p;
p=list;
if(list==NULL)
printf("\nunderflow ");
else
if(list->next==NULL)
{
printf("\ndeleted elelment is %d",list->d);
list=NULL;
}
else
{
printf("\ndeleted elelment is %d",list->d);
list=list->next;
list->prev=NULL;
}
}
void display()
{
l *p;
p=list;
if(p==NULL)
printf(" empty");
else
if(p->next==NULL)
printf("\n %d",p->d);
else
{
while(p->next!=NULL)
{
printf("\n %d",p->d);
p=p->next;
}
printf("\n %d",p->d);
}
}
void rdisplay()
{
l *p;
p=list;
printf("\nreversed elements\n");
if(p==NULL)
printf(" empty");
else
if(p->next==NULL)
printf("\n %d",p->d);
else
{
while(p->next!=NULL)
{
p=p->next;
}
while(p->prev!=NULL)
{
printf("\n %d",p->d);
p=p->prev;
}
printf("\n %d",p->d);
}
}
main()
{
l *list;
int choice,x,b,c;
do
{
printf("\n1. insert front\n2. delete front\n3.display\n4.reverse display\n 5.exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("\nEnter the element to inserted ");
        scanf("%d",&x);
        insertfornt(x);
        break;

        break;
case 2: deletefront();
        break;
case 3: display();
        break;
case 4: rdisplay();
        break;  
case 5 : break;
}
}while(choice!=5);
}
