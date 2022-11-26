#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>
sem_t mutex,writeblock;
long int data=0,rcount=0;
void *reader(void *arg)
{int f;
f=((long int)arg);
sem_wait(&mutex);
rcount=rcount+1;
if(rcount==1)
sem_wait(&writeblock);
sem_post(&mutex);
printf("data read by the reader %d id %ld\n",f,data);
sleep(1);
sem_wait(&mutex);
rcount=rcount-1;
if(rcount==0)
sem_post(&writeblock);
sem_post(&mutex);
}
void *writer(void *arg)
{int f;
f=((long int)arg);
sem_wait(&writeblock);
data++;
printf("data written by the writer %d id %ld\n",f,data);
sleep(1);
sem_post(&writeblock);
}
int main()
{
 long int i;
int b,pr;
pthread_t rtid[10],wtid[10];
sem_init(&mutex,0,1);
sem_init(&writeblock,0,1);
printf("enter no of process you want to create==");
scanf("%d",&pr);
for(i=0;i<pr;i++)
{
pthread_create(&wtid[i],NULL,writer,(void*)(long)i);
pthread_create(&rtid[i],NULL,reader,(void*)(long)i);

}
for(i=0;i<=pr;i++)
{
pthread_join(wtid[i],NULL);
pthread_join(rtid[i],NULL);
}}

