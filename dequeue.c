#include<stdio.h>
#include<string.h>
#define maxqueue 10
typedef struct queue
{
int front;
int rear;
int entry[maxqueue];
}queue;
void createqueue(queue *q)
{
q->front=0;
q->rear=-1;
}
int queuefull(queue *q)
{
return q->rear>=maxqueue-1;
}
int queueempty(queue *q)
{
return q->rear<=0;
}
int insertfirst(int item,queue *q)
{
if(queuefull(q))
{
printf("queue full\n");
}
else if(q->front>0 )
{
q->entry[--q->front]=item;
}
else
return 0;
}
int deletefirst(int *item,queue *q)
{
if(queueempty(q))
{
printf("queue is empty\n");
}
else
{
*item=q->entry[q->front++];
}
}

int insertlast(int item,queue *q)
{
if(queuefull(q))
{
printf("queue full\n");
}
else if(q->rear<maxqueue)
{
q->entry[++q->rear]=item;
}
else
return 0;
}
int deletelast(int *item,queue *q)
{
if(queueempty(q))
{
printf("queue is empty\n");
}
else
{
*item=q->entry[q->rear--];
}
}
void display(queue *q)
{
int i;
if(queueempty(q))
{
printf("queue is empty");
}
else
{
printf("the contents of queue are:");
for(i=q->front;i<=q->rear;i++)
{
printf("%d\t",q->entry[i]);
}
}
printf("\n");
}
int main()
{
queue q;
int i,c,n[10];
createqueue(&q);
printf("enter the queue:");
for(i=0;i<6;i++)
{
scanf("%d",&n[i]);
}
printf("3 elements are inserted last\n");
for(i=0;i<3;i++)
{
insertlast(n[i],&q);
}
display(&q);
printf("2 elements are deleted first\n");
for(i=0;i<2;i++)
{
deletefirst(&c,&q);
}
display(&q);
printf("2 elements are inserted first\n");
for(i=3;i<5;i++)
{
insertfirst(n[i],&q);
}
display(&q);
printf("delete last element\n");
deletelast(&c,&q);
display(&q);
}
