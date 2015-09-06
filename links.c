/*sandeep
 bl.en.u4cse09038
singular link list*/
#include<stdio.h>
struct node
{
int data;
struct node *next;
}*list=NULL;
int insf(int a)
{
struct node *temp,*p;
if(list==NULL)
{
list=(struct node *)malloc(sizeof(struct node));
list->data=a;
list->next=NULL;
}
else
{
temp=(struct node *)malloc(sizeof(struct node));
temp->data=a;
temp->next=list;
list=temp;
}
}
int insr(int a)
{
struct node *temp,*p;
if(list==NULL)
{
list=(struct node *)malloc(sizeof(struct node));
list->data=a;
list->next=NULL;
}
else
{
temp=(struct node *)malloc(sizeof(struct node));
temp->data=a;
temp->next=NULL;
p=list;
while(p->next!=NULL)
p=p->next;
p->next=temp;
}
}
void delf()
{
if(list==NULL)
{
printf("under flow at front\n");
}
else
{
list=list->next;
}
}
void delr()
{
struct node *p;
if(list==NULL)
{
printf("under flow at rear\n");
}
else
{
p=list;
}
while(p!=NULL)
{
p=p->next->next;
}
p->next=NULL;
}
void display()
{
struct node *p;
p=list;
if(p==NULL)
printf("\nlist is empty");
else
if(p->next==NULL)
printf("\nelements in list is %d",p->data);
else
{
while(p->next!=NULL)
{
printf("\nelements in list is %d",p->data);
p=p->next;
}
printf("\nelements in list is %d",p->data);
}
}
int main()
{
int ch,item,it;
do
{
printf("\n1.insert front \n2.insert rear\n3.delete rear\n4.delete front\n5.display\n6.exit\n");
printf("enter the choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("enter the item to be inserted");
scanf("%d",&item);
insf(item);
break;
case 2:
printf("enter the element to be inserted");
scanf("%d",&it);
insr(it);
break;
case 3:
delr();
break;
case 4:
delf();
break;
case 5:
display(); 
break; 
case 6:
return(0);
break;
}
}while(1);
}   
/*output:
1.insert front 
2.insert rear
3.delete rear
4.delete front
5.display
6.exit
enter the choice
1
enter the item to be inserted22

1.insert front 
2.insert rear
3.delete rear
4.delete front
5.display
6.exit
enter the choice
1
enter the item to be inserted99

1.insert front 
2.insert rear
3.delete rear
4.delete front
5.display
6.exit
enter the choice
5

elements in list is 99
elements in list is 22
1.insert front 
2.insert rear
3.delete rear
4.delete front
5.display
6.exit
enter the choice
4

1.insert front 
2.insert rear
3.delete rear
4.delete front
5.display
6.exit
enter the choice
5

elements in list is 22
*/
