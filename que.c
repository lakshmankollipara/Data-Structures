#include<stdio.h>
#include<string.h>
#define max 5
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
int insert(int item,queue *q)
{if (QueueFull(q))
   printf("que is full\n");
 else 
    if(q->rear<max)
      { q->entry[++q->rear]=item;}
    else return 0;
}
int delete(int *item,queue *q)
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
}

main()
{queue q;
 int i,n[10],c;
 createqueue(&q);
 printf("enter the array\n");
 for(i=0;i<6;i++)
  scanf("%d",&n[i]);
 printf("insert 3 elements from array to queue\n");
 for(i=0;i<3;i++)
  insert(n[i],&q);
 printf("delete 2 items from queue\n");
 for(i=0;i<2;i++)
  delete(&c,&q);
 printf("insert 3 elements from array to queue\n");
 for(i=0;i<3;i++)
  insert(n[i],&q);
 display(&q); 
}

