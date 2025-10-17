#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int main ()
{
	struct node *n1,*n2,*n3,*head;
	n1=(struct node*)malloc(sizeof(struct node));
	n2=(struct node*)malloc(sizeof(struct node));
	n3=(struct node*)malloc(sizeof(struct node));
	n1->next=n2;
	n1->data=10;
	n2->next=n3;
	n2->data=20;
	n3->next=NULL;
	n3->data=30;
	head=n1;
	while(head!=NULL);
	{
		printf("\n%d",head->data);
		head=head->next;
	}
	free(n1);
	free(n2);
	free(n3);
	return 0;
}
