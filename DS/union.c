#include<stdio.h>
#pragma pack(1)
union student 
{
	int rno;
	char name[20];
	float avg;
};
int main ()
{
	union student s1;
	printf("memory allocated=%d \n",sizeof(s1));
	s1.rno=55;
	print
	strcpy(s1.name,"raju");
	print
	s1.avg=55.2;
	print
	
