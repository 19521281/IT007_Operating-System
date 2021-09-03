#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

pthread_t tid[2];
sem_t sem, full, empty;
int n = 81281, a[81281];

void* Push_num()
{
	int value;
	while(1)
	{
		sem_wait(&empty);
		sem_wait(&sem);
		sem_getvalue(&full, &value);
		
		a[value] = rand() % (n - 1);
		printf("\nSo phan tu cua mang a sau khi push: %d", ++value);
		
		sem_post(&sem);
		sem_post(&full);
	}
}

void* Pop_num()
{
	int value;
	while(1)
	{	
		sem_wait(&full);
		sem_wait(&sem);
		sem_getvalue(&full, &value);
		
		if(value > 0)
		{
			int pos = rand() % value;	
			for(int s = pos; s < value; s++)
				a[s] = a[s+1];
			printf("\nSo phan tu cua mang a sau khi pop: %d", value);
		}
		else
			printf("\nNothing in array a");
			
		sem_post(&sem);
		sem_post(&empty);
	}
}

int main()
{
	sem_init(&sem, 0, 1);
	sem_init(&full, 0, 0);
	sem_init(&empty, 0, n);
	
	pthread_create(&tid[0], NULL, Push_num, NULL);
	pthread_create(&tid[1], NULL, Pop_num, NULL);
	
	for(int p = 0; p < 2; p++)
		pthread_join(tid[p], NULL); 
}

