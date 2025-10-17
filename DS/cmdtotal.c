#include<stdio.h>
struct student 
{
	char name [40];
	int m1,m2,m3,m4;
	float tot;
};
int main (int argc , char*argv[])
{
	struct student s1;
	if(argc>=6)
	{
		strcpy(s1.name,argv[1]);
		s1.m1=atoi(argv[2]);
		s1.m2=atoi(argv[3]);
		s1.m3=atoi(argv[4]);
		s1.m4=atoi(argv[5]);
		s1.tot=s1.m1+s1.m2+s1.m3+s1.m4;
		printf("student name and total marks:\n");
		printf("%s\t\t%f",s1.name,s1.tot);
	}
	else{
		printf("enter atleast 6 arguments");
	}
	return 0;
}
