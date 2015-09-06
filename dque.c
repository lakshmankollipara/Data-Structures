#include<stdio.h>
#include<string.h>
#define max 10
typedef struct queue
{int front;
 int rear;
 int entry[max];
}queue;
int QueueFull(queue *q)
{ return q->rear>=max-1;

 }
int QueueEmpty(queue *q)
{ return q->rear<0;

 }
void createqueue(queue *q)
{q->front=0;
 q->rear=-1;
}
int insertlast(int item,queue *q)
{if (QueueFull(q))
   printf("que is full\n");
else
    if(q->rear<max)
      { q->entry[++q->rear]=item;}
    else return 0;
}
int insertfirst(int item,queue *q)
{if(QueueFull(q))
  printf("que is full\n");
 else
  if(q->front>0)
  {q->entry[--q->front]=item;} 
  else return 0;
}
int deletelast(int *item,queue *q)
{if(QueueEmpty(q))
  printf("que is empty\n");
 else {*item=q->entry[q->rear--];}
}
int deletefirst(int *item,queue *q)
{if(QueueEmpty(q))
   printf("que is empty\n");
 else {*item=q->entry[q->front++];
      }
}
display(queue *q)
{int i;
 printf("the contents of queue are\n");
 for(i=q->front;i<=q->rear;i++)
  printf("%d\t",q->entry[i]);
 printf("\n");
}

main()
{queue q;
 int i,n[10],c;
 createqueue(&q);
 printf("enter the array\n");
 for(i=0;i<6;i++)
  scanf("%d",&n[i]);
 printf("insert 3 elements at last\n");
 for(i=0;i<3;i++)
  insertlast(n[i],&q);
 display(&q);
 printf("delete 1st 2 elements\n");
 for(i=0;i<2;i++)
  deletefirst(&c,&q);
 display(&q);
 printf("Insert 2 elements at 1st\n");
 for(i=3;i<5;i++)
  insertfirst(n[i],&q);
 display(&q);
 printf("delete last element\n"); 
  deletelast(&c,&q);
 display(&q);
}

