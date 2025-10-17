#include<stdio.h>
//Coded by P.Likhitha
void RadixSort (int a[ ],int n)
{
	int digits=0,big,i,bucket[10][n],count[10],div=1,j,k,steps,pos;
	big=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>big)
		big=a[i];
	}
	while(big>0)
	{
		digits++;
		big=big/10;
	}
	for(steps=1;steps<=digits;steps++)
	{
		for(j=0;j<10;j++)
		{
			count[j]=0;
		}
		for(i=0;i<n;i++)
		{
			pos=(a[i]/div)%10;
			bucket[pos][count[pos]++]=a[i];
		}
		k=0;
		for(i=0;i<10;i++)
		{
			for(j=0;j<count[i];j++,k++)
			{
				a[k]=bucket[i][j];
			}
		}
		div=div*10;
	}
}
int main()
{
	int arr[25],n,i;
	printf("Enter n value: ");
	scanf("%d",&n);
	printf("Enter %d values: ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	RadixSort(arr,n);
	printf("Sorted array is: ");
	for(i=0;i<n;i++)
	{
		printf(" %d",arr[i]);
	}
             printf("\nRoll no:24B11CS351");
	return 0;
}

