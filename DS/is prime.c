#include<stdio.h>
int isprime(int n)
{
	int i;
	for (i=2;i<n/2;i++)
	{
		if(n%i==0)
		{
			return 0; //not a prime
		}
	}
	return 1;
}
int main()
{
	int n,x;
	printf("enter any numb : ");
	scanf("%d",&n);
	if(n==1)
	printf("1 is neither prime nor composite");
	x=isprime(n);
	if (x==1)
	printf("it is  a prime");
	else
	printf("it is not a prime");
}
