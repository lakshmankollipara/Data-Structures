#include<stdio.h>
#include<string.h>
#define maxqueue 10
typedef struct queue
{
int count,count1;
int front,front1;
int rear,rear1;
int entry[maxqueue];
int entry1[maxqueue];
}queue;
void createqueue(queue *q)
{
q->count=0;
q->count1=0;
q->front=0;
q->front1=0;
q->rear=-1;
q->rear1=-1;
}
int queuefull(queue *q,int p)
{
if(p==1)
{
return q->count>=maxqueue;
}
else
{
return q->count1>=maxqueue;
}
}
int queueempty(queue *q,int p)
{
if(p==1)
{
return q->count<=0;
}
else
{
return q->count1<=0;
}
}
void insert(int item,queue *q,int p)
{
if(queuefull(q,p))
{
printf("queue full\n");
}
else if(p==1)
{
q->count++;
q->rear=(q->rear++)%maxqueue;
q->entry[q->rear]=item;
}
else
{
q->count1++;
q->rear1=(q->rear1++)%maxqueue;
q->entry1[q->rear1]=item;
}
}
void delete(int *item,queue *q)
{
if((queueempty(q,1))&&(queueempty(q,2)))
{
printf("both the queues are empty\n");
}
else if(queueempty(q,1))
{
q->count1--;
*item=q->entry1[q->front1];
q->front1=(q->front1+1)%maxqueue;
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
if(queueempty(q,1))
printf("queue of priority 1 is empty\n");
else
{
printf("the contents of queue1 are:");
if(q->rear>q->front)
{
for(i=q->front;i<=q->rear;i++)
{
printf("%d\t",q->entry[i]);
}
printf("\n");
}
else
{
for(i=q->front;i<=maxqueue;i++)

printf("%d\t",q->entry[i]);

for(i=0;i<=q->rear;i++)

printf("%d\t",q->entry[i]);
printf("\n");
}
}
if(queueempty(q,2))

printf("queue of priority2 is empty");

else 
{
printf("the contents of queue2 are:");
if(q->rear1>q->front1)
{
for(i=q->front1;i<=q->rear1;i++)

printf("%d\t",q->entry1[i]);
printf("\n");
}
else
{
for(i=q->front1;i<=maxqueue;i++)

printf("%d\t",q->entry1[i]);

for(i=0;i<=q->rear1;i++)

printf("%d\t",q->entry1[i]);
printf("\n");
}
}
}
int main()
{
queue q;
int i,a[10],b[10],d;
createqueue(&q);
printf("enter the queue1:");
for(i=0;i<6;i++)
{
scanf("%d",&a[i]);
}
printf("enter the queue2:\n");
for(i=0;i<6;i++)
{
scanf("%d",&b[i]);
}
for(i=0;i<6;i++)
{
insert(a[i],&q,1);
}
for(i=0;i<6;i++)
{
insert(b[i],&q,2);
}
display(&q);
for(i=0;i<10;i++)
{
delete(&d,&q);
}
display(&q);
}
