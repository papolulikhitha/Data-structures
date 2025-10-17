#include<stdio.h>
#include<stdlib.h>
struct population
{
	int members;
	char place[40];
	float income;
};
int main ()
{
	struct population *s1;
	int n,i;
	scanf("%d",&n);
	s1 =(struct population*)malloc(n*sizeof(struct population));
	for (i=0;i<n;i++)
	{
		printf("enter membs,place,income:");
		scanf("%d %s %f",&(s1+i)->members,&(s1+i)->place,&(s1+i)->income );
	}
	for (i=0;i<n;i++)
	{
		
		printf("\n%d,%s,%.2f",(s1+i)->members,(s1+i)->place,(s1+i)->income);
	}
	return 0;
}
