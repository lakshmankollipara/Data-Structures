#include<stdio.h>
#include<string.h>
#define maxqueue 5
typedef int queueentry;
typedef struct queue
{
int front;
int rear;
queueentry entry[maxqueue];
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
int insert(queueentry item,queue *q)
{
if(queuefull(q))
{
printf("queue full\n");
}
else if(q->rear<maxqueue)
{
q->entry[++q->rear]=item;
}
else return 0;
}
int delete(queueentry *item,queue *q)
{
if(queueempty(q))
{
printf("queue is empty");
}
else
{
*item=q->entry[q->front++];
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
}
int main()
{
queue q;
int i,c,n[6];
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
