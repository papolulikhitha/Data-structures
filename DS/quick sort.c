#include<stdio.h>
//Coded by P.Likhitha
void QuickSort(int a[],int left,int right)
{
	int i,j,t,pivot;
	if(left<right)
	{
	    pivot=left;
		i=left;
		j=right;
		while(i<j)
		{
			while(a[i]<=a[pivot]&&i<right)
			i++;
			while(a[j]>a[pivot])
			j--;
			if(i<j)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		t=a[j];
		a[j]=a[pivot];
		a[pivot]=t;
		QuickSort(a,left,j-1);
		QuickSort(a,j+1,right);
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
	QuickSort(arr,0,n-1);
	printf("Sorted array is: ");
	for(i=0;i<n;i++)
	{
		printf(" %d",arr[i]);
	}
             printf("\nRoll no:24B11CS351");
	return 0;
}

