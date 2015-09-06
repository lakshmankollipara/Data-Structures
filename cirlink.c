#include<stdio.h>
struct node
{
int d;
struct node *next;
}*list=NULL,*head=NULL;

void insert(int a)
{
struct node *temp,*p;
if(list==NULL)
{
list=(struct node *)malloc(sizeof(struct node));
list->d=a;
list->next=list;
head=list;
}
else
{
temp=(struct node *)malloc(sizeof(struct node));
temp->d=a;
temp->next=NULL;
p=list;
while(p->next!=NULL)
p=p->next;
p->next=temp;
temp->next=list;
head=p;
}
}
void delete()
{
struct node *p;
p=list;
if(list==NULL)
printf("\nunderflow ");
else
if(list==head)
{
printf("\ndeleted elelment is %d",list->d);
list=NULL;
}
else
if(list->next==head)
{
printf("\ndeleted elelment is %d",list->d);
head->next=NULL;
}
else
{
printf("\ndeleted elelment is  %d",list->d);
list=list->next;
}
}
void display()
{
struct node *p;
p=list;
if(p==NULL)
printf("\nqueue is empty");
else
if(p->next==list)
printf("\nelements in queue is %d",p->d);
else
{
while(p->next!=list)
{
printf("\nelements in queue is %d",p->d);
p=p->next;
}
printf("\nelements in queue is %d",p->d);
}
}
main()
{
struct node *list,*head;
int choice,x,b,c;
do
{
printf("\n\nMENU:\n1.Insert \n2.Delete \n3.Display\n4.Exit\nenter your choice\t");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("\nEnter the element to insert ");
        scanf("%d",&x);
        insert(x);
        break;
case 2: delete();
        break;
case 3: display();
	break;
case 4: break;
}
}while(choice!=4);
}
