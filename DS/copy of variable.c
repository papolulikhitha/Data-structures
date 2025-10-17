#include<stdio.h>
//Coded by P.Likhitha.
struct student
{
	int rno;
	char name[30];
	float avg;
}s1,s2;
int main()
{
	struct student s3={351,"likky",77.7};
	s2=s3;
    printf("enter rollno,name,average: ");
	scanf("%d,%s,%f",&s1.rno,&s1.name,&s1.avg);
	printf("details are :");
	printf("%d,%s,%f\n",s1.rno,s1.name,s1.avg);
	printf("%d,%s,%f\n",s2.rno,s2.name,s2.avg);
	printf("%d,%s,%f\n",s3.rno,s3.name,s3.avg);
	
          printf("Roll no:24B11CS351");	
	return 0;

}


