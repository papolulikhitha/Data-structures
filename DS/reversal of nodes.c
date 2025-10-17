#include<stdio.h>
#include<stdlib.h>
struct node *head=NULL, *end=NULL,*next=NULL;
int count=0;
struct node
{
	int data;
	struct node *next;
};
void create_nodes()
{
	int info;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("overflow");
		return ;
	}
	printf("enter data into a node ");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=end=newnode;
	}
	else
	{
		end->next=newnode;
		end=newnode;
	}
	count++;
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
	printf("\n list is empty");
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data );
		temp=temp->next;
	}
}
void reverse()
{
	struct node *prev=NULL,*curr=head,*next=NULL;
	if(head==NULL)
	{
		printf("\n list is empty");
		return;
	}
	end=head;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	head=prev;
	printf("\n----list is reversed-----");
}
int main()
{
	char ch;
    while(1)
   {
   	printf("\n*******menu*******");
   	printf("\n1.create \n2.display \n3.reverse \n4.exit");
   	printf("\n enter your choice");
   	scanf("%d",&ch);
   	switch(ch)
   	{
   		case 1:create_nodes();break;
   		case 2:display();break;
   		case 3:reverse();break;
   		case 4:exit(0);
   		default:printf("invalid choice");
	   }
   }
   return 0;
}
