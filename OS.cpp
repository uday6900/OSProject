#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>
pthread_t t1;
pthread_mutex_t counter;
typedef struct
{
	char name[10];
	int pos;
	int ngift;
}billing;
void *bill()
{
	pthread_mutex_lock(&counter);
	printf(" Getting billed\n");
	
	printf("Billing is going on please wait\n");
	
	pthread_mutex_unlock(&counter);
	printf("\n\nNext Please\n");
}
int main()
{
	int n;
	billing d[100],t;
	printf("Enter no of students\n");
	scanf("%d",&n);
	printf("Enter the students for billing with their positions:\n");
	printf("Also enter the no of gifts an individuals\n");
	for(int i=0;i<n;i++)
	{
		scanf("%s",d[i].name);
		scanf("%d",&d[i].pos);
		scanf("%d",&d[i].ngift);
	}
	printf("\nSort them According to no of gifts they have\n");
	printf("If any of them has equal no of gifts then sort w.r.t position\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
			{
			if(d[j].ngift<d[j+1].ngift)
				{
				t=d[j];
				d[j]=d[j+1];
				d[j+1]=t;
				}
			else if(d[j].ngift==d[j+1].ngift)
			{
				if(d[j].pos>d[j+1].pos)
				{
					t=d[j];
					d[j]=d[j+1];
					d[j+1]=t;
				}
			}
			}
	}
	for(int i=0;i<n;i++)
	{
		printf("%s with %d gifts \n",d[i].name,d[i].ngift);
	}
	pthread_exit(NULL);
}
