#include<stdio.h>
struct data 
{
 int dd;
 int mm;
 int yy;	
};
struct student
{
	int rno;
	struct data dob;
	char name[30];
};

	int main ()
	{
		struct student s1={501,{2,12,2006},"sudan"};
		printf("%d\t%d-%d-%d\t%s\t",s1.rno,s1.dob.dd,s1.dob.mm,s1.dob.yy,s1.name);	
		
	return 0;
   }
