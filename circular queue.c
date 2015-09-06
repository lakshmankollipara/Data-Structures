#include<stdio.h>
#include<string.h>
#define maxqueue 10
typedef int queueentry;
typedef struct queue
{
int count;
int front;
int rear;
queueentry entry[maxqueue];
}queue;
void createqueue(queue *q)
{
q->count=0;
q->front=0;
q->rear=-1;
}
int queuefull(queue *q)
{
return q->count>=maxqueue-1;
}
int queueempty(queue *q)
{
return q->count<=0;
}
int insert(queueentry item,queue *q)
{
if(queuefull(q))
{
printf("queue full\n");
}
else
{
q->count++;
q->rear=(q->rear+1)%maxqueue;
q->entry[q->rear]=item;
}
}
int delete(queueentry *item,queue *q)
{
if(queueempty(q))
{
printf("queue is empty\n");
}
else
{
q->count--;
*item=q->entry[q->front];
q->front=(q->front+1)%maxqueue;
}
}
void display(queue *q)
{
int i;
if(queueempty(q))
{
printf("queue is empty");
}
else if(q->rear>q->front)
{
printf("the contents of queue are:");
for(i=q->front;i<=q->rear;i++)
{
printf("%d\t",q->entry[i]);
}
}
else
{
printf("the contents of queue are:");
for(i=q->front;i<=maxqueue;i++)
{
printf("%d\t",q->entry[i]);
}
for(i=0;i<=q->rear;i++)
{
printf("%d\t",q->entry[i]);
}
}
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
printf("3 elements are inserted to queue\n");
for(i=0;i<3;i++)
{
insert(n[i],&q);
}
printf("2 elements are deleted from queue\n");
for(i=0;i<2;i++)
{
delete(&c,&q);
}
printf("3 elements are inserted to queue\n");
for(i=0;i<3;i++)
{
insert(n[i],&q);
}
display(&q);
}

