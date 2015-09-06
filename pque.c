#include<stdio.h>
#define max 10
typedef struct queue
{int front,rear,count,count1,front1,rear1;
 int entry[max];
 int entry1[max];
 }queue;
int QueueFull(queue *q,int prior)
{ if(prior==1)
  return q->count>=max;
  else return q->count1>=max;
 }
int QueueEmpty(queue *q,int prior)
{if(prior==1)
  return q->count<=0;
  else return q->count1<=0;
 }
void createqueue(queue *q)
{q->count1=0;
 q->count=0;
 q->front=0;
 q->rear=-1;
 q->front1=0;
 q->rear1=-1;
}
void append(int item,queue *q,int prior)
{if(QueueFull(q,prior))
   printf("que is full\n");
 else
     if(prior==1)
     {q->count++;
      q->rear=(q->rear++)%max;
      q->entry[q->rear]=item;
    }
 else {q->count1++;
      q->rear1=(q->rear1++)%max;
      q->entry1[q->rear1]=item;
    }
}

void serve(int *item,queue *q)
{if((QueueEmpty(q,1))&&(QueueEmpty(q,2)))
{ printf("Both the queues are empty\n");}
else
if(QueueEmpty(q,1)) 
{ q->count1--;
  *item=q->entry1[q->front1];
  q->front1=(q->front1+1)%max;
}
else{  q->count--;
           *item=q->entry[q->front];
           q->front=(q->front+1)%max;
    
  }}    
           
 
void display(queue *q)
{int i;
 if(QueueEmpty(q,1))
  printf("The Queue with priority 1 is Empty\n");
else
{printf("Queue 1:");
 if(q->rear>q->front)
 {for(i=q->front;i<=q->rear;i++)
  {printf("%d\t",q->entry[i]);}
   printf("\n");
 }
 else
 {for(i=q->front;i<=max;i++)
  {printf("%d\t",q->entry[i]);}
  for(i=0;i<=q->rear;i++)
  {printf("%d\t",q->entry[i]);}
  printf("\n");
 }}

if(QueueEmpty(q,2))
  printf("The Queue with priority 2 is Empty\n");
else
{printf("Queue 2:");
if(q->rear1>q->front1)
 {for(i=q->front1;i<=q->rear1;i++)
  {printf("%d\t",q->entry1[i]);}
   printf("\n");
 }
 else
 {for(i=q->front1;i<=max;i++)
  {printf("%d\t",q->entry1[i]);}
  for(i=0;i<=q->rear1;i++)
  {printf("%d\t",q->entry1[i]);}
  printf("\n");
 }
}}


main()
{queue q;
 int i,a[10],b[10],d;
 createqueue(&q);
 printf("enter the 1st array\n");
 for(i=0;i<6;i++)
  scanf("%d",&a[i]);
 printf("enter the 2nd array\n");
 for(i=0;i<6;i++)
  scanf("%d",&b[i]);
 for(i=0;i<6;i++)
  append(a[i],&q,1);
  for(i=0;i<6;i++)
  append(b[i],&q,2);
display(&q);
for(i=0;i<10;i++)
{serve(&d,&q);}
display(&q);
}



