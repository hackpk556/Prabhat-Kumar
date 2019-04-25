//Prabhat kumar mahato
//reg no: 11718252
//roll no:59

#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
void *fun1();
void *fun2();
void *fa()
{
	printf("Fa is completed\n");
}
void *fb()
{
	printf("Fb is completed\n");
}
void *fc()
{
	printf("Fc is completed\n");
}

sem_t m;
sem_t n;
int main()
{
sem_init(&m,0,1);
sem_init(&n,0,1);
pthread_t thread1;
pthread_create(&thread1, NULL, fun1, NULL);
pthread_join(thread1, NULL);
}
void *fun1()
{
pthread_t thread2;
pthread_create(&thread2, NULL, fun2, NULL);
pthread_join(thread2, NULL);
sem_wait(&m);
//fb();
fc();
sem_post(&n);
//P(m); 
//fb();
//V(n); 
}


void *fun2()
{
fa();
sem_post(&m);
sem_wait(&n);
//fc();
fb();
//V(m);
//P(n);
//fc();
}
