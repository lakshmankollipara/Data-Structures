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
void insertlast(int a)
{
l *temp,*p;
if(list==NULL)
{
list=(l*)malloc(sizeof(l));
list->d=a;
list->next=list->prev=NULL;
}
else
{
temp=(l*)malloc(sizeof(l));
temp->d=a;
temp->next=NULL;
p=list;
while(p->next!=NULL)
p=p->next;
temp->prev=p;
p->next=temp;
}
}
void deletelast()
{
l *p;
p=list;
if(list==NULL)
printf("\nunderflow ");
else
if(list->next==NULL)
{
printf("\ndeleted elelment at last is %d",list->d);
list=NULL;
}
else
{
while(p->next->next!=NULL)
p=p->next;
printf("\ndeleted elelment at last is %d",p->next->d);
p->next=NULL;
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
printf("\ndeleted elelment at front is %d",list->d);
list=NULL;
}
else
{
printf("\ndeleted elelment at front is %d",list->d);
list=list->next;
list->prev=NULL;
}
}
void deletepar(int a)
{
int i=0;
l *p;
if(list==NULL)
{
printf("\nno elements in list");
i++;
}
else
if(list->d==a)
{
printf("\ndeleted element is %d",list->d);
list=list->next;
i++;
}
else
{
p=list;
while(p->next!=NULL)
{
if(p->next->d==a)
{
printf("\ndeleted elelment is %d",p->next->d);
p->next=p->next->next;
if(p->next!=NULL)
p->next->prev=p;
i++;
}
else
{
p=p->next;
}
}
}
if(i==0)
printf("\nelement not found");
}
void display()
{
printf("\nelements in list is ");
l *p;
p=list;
if(p==NULL)
printf(" empty");
else
if(p->next==NULL)
printf("\t %d",p->d);
else
{
while(p->next!=NULL)
{
printf("\t %d",p->d);
p=p->next;
}
printf("\t %d",p->d);
}
}
main()
{
l *list;
int choice,x,b,c;
do
{
printf("\n\nMENU:\n1.Insert front\n2.Insert last\n3.Delete front\n4.Delete last\n5.Delete at particular\n6.Display\n7.Exit\nenter your choice\t");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("\nEnter the element to insert front ");
        scanf("%d",&x);
        insertfornt(x);
        break;
case 2: printf("\nEnter the element to insert last ");
        scanf("%d",&x);
        insertlast(x);
        break;
case 3: deletefront();
        break;
case 4: deletelast();
        break;
case 5: printf("\nenter the element to be deleted ");
        scanf("%d",&c);
        deletepar(c);
        break;
case 6: display();
        break;
case 7: break;
}
}while(choice!=7);
}
