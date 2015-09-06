#include<stdio.h>
#define max 10
typedef struct queue
{int front,rear,count;
 int entry[max];
}queue;
int QueueFull(queue *q)
{ return q->count>=max;

 }
int QueueEmpty(queue *q)
{ return q->count<0;

 }
void createqueue(queue *q)
{q->count=0;
 q->front=0;
 q->rear=-1;
}
void append(int item,queue *q)
{if (QueueFull(q))
   printf("que is full\n");
 else
     {q->count++;
      q->rear=(q->rear++)%max;
      q->entry[q->rear]=item;
    }
}
void serve(int *item,queue *q)
{if(QueueEmpty(q))
   printf("que is empty\n");
 else {q->count--;
       *item=q->entry[q->front];
       q->front=(q->front+1)%max;
      }
}
void display(queue *q)
{int i;
 printf("the contents of the queue are\n");
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
 }
}
main()
{queue q;
 int i,n[10],c;
 createqueue(&q);
 printf("enter the array\n");
 for(i=0;i<6;i++)
  scanf("%d",&n[i]);
 for(i=0;i<6;i++)
  append(n[i],&q);
display(&q); 
for(i=0;i<4;i++)
  serve(&c,&q);
display(&q); 
 for(i=0;i<6;i++)
  append(n[i],&q);
display(&q);
}
