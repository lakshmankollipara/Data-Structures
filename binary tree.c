#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *left;
int data;
struct node *right;
}*root;
//typedef struct node* nod*;
struct node* create(struct node *t,int ele)
{
if(t==NULL)
{
t=(struct node*)malloc(sizeof(struct node));
t->left=NULL;
t->right=NULL;
t->data=ele;
return t;
}
else if(ele==t->data)
{
printf("invalid");
return t;
}
else if(ele>t->data)
t->right=create(t->right,ele);
else if(ele<t->data)
t->left=create(t->left,ele);
return t;
}

void pre_order(struct node *p)
{
if(p!=NULL)
{
printf("%d  ",p->data);
pre_order(p->left);
pre_order(p->right);
}
}

void in_order(struct node *p)
{
if(p!=NULL)
{
in_order(p->left);
printf("%d  ",p->data);
in_order(p->right);
}
}

void post_order(struct node *p)
{
if(p!=NULL)
{
post_order(p->left);
post_order(p->right);
printf("%d  ",p->data);
}
}

struct node*  search(struct node *p,int x)
{
if((p==NULL)||(p->data==x))
return p;
else if(x>p->data)
search(p->right,x);
else
search(p->left,x);
}

void delete(struct node *p,int x)
{
int a;
struct node *pt,*pt1,*p1;
if(p->data==x)
pt=p;
while((p!=NULL)&&(p->data!=x))
if(x>p->data)
{
pt=p;
p=p->right;
}
else
{
pt=p;
p=p->left;
}
 if((p->right==NULL)&&(p->left==NULL))
{
if(x>pt->data)
pt->right=NULL;
else
pt->left=NULL;
printf("terminal node deleted\n");
}
else if((p->right==NULL)&&(p->left!=NULL))
{
if(pt->left==p)
pt->left=p->left;
else
pt->right=p->left;
printf("Non-terminal node deleted\n");
}
else if((p->right!=NULL)&&(p->left==NULL))
{
if(pt->right==p)
pt->right=p->right;
else
pt->left=p->right;
printf("Non-terminal node deleted\n");

}
else if((p->right!=NULL)&&(p->left!=NULL))
{ pt1=p;
p1=p;
p1=p1->right;
while(p1->left!=NULL)
{
pt1=p1;
p1=p1->left;
}
p->data=p1->data;
if(pt1->left==p1)
pt1->left=p1->right;
else
pt1->right=p1->right;
printf("Non-terminal node deleted\n");

}
}
main()
{
struct node *p;
int num,ch=1;
root=NULL;
while(ch<5)
{
printf("1.INSERT\t2.DELETE\t3.DISPLAY\t4.SEARCH:\t");
scanf("%d",&ch);
switch(ch)
{
case 1:
 printf("enter value:");
 scanf("%d",&num);
 root=create(root,num);
 break;
case 2:
 printf("enter value to be deleted:");
 scanf("%d",&num);
if((root->data==num)&&((root->right==NULL)&&(root->left==NULL)))
{
 root=NULL;
 printf("root node deleted\n");
}
else
 delete(root,num);
 break;
case 3: 
if(root!=NULL)
{
 printf("pre_order=   ");
 pre_order(root);
 printf("\nin_order=  ");
 in_order(root);
 printf("\npost_order= ");
 post_order(root);
 printf("\n");
}
else
 printf("NULL\n");
 break;
case 4:
 printf("enter value to be searched:");
 scanf("%d",&num);
 p=search(root,num);
if(p!=NULL)
 printf("element found %d",p->data);
else
 printf("element not found");
 printf("\n");
 break;
}
}
}
                                                                            

