#include<stdio.h>
//Coded by P.Likhitha
struct student
{
	int rno;
	int C,M,B,Ch;
	float tot,avg;
};
int main()
{
	struct student std[100];
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter rollno and 4subject marks: ");
		scanf("%d%d%d%d%d",&std[i].rno,&std[i].C,&std[i].M,&std[i].B,&std[i].Ch);
	}
	printf("Roll no,Total and average is: ");
	for(i=0;i<n;i++)
	{
		std[i].tot=std[i].C+std[i].B+std[i].M+std[i].Ch;
		std[i].avg=(std[i].tot/4);
		printf("\nroll no:%d\ntotal:%f\naverage:%f\n",std[i].rno,std[i].tot,std[i].avg);
printf("Roll no:24B11CS351");
	}
	return 0;
}


