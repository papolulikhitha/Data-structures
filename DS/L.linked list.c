#include<stdio.h>
#include<stdlib.h>
void create_nodes();
void display();
void insert_end();
void insert_any();
void insert_beg();
void delete_beg();
void delete_end();
struct node *head,*end;
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
		printf("Overflow\n");
        return;
	}
	printf("\nEnter data into a node :");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=NULL;
	if(head==NULL)
	head=end=newnode;
	else
	{
		end->next=newnode;
		end=newnode;
	}
	count++;
	printf("---Node is Created---\n");
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	temp=head;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void insert_end()
{
	int info;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\n*Memory is not created*\n");
		return;
	}
	printf("\nEnter data into Node:");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=NULL;
	end->next=newnode;
	end=newnode;
	count++;
	printf("---Node is Added---\n");
}
void insert_any()
{
	int info,pos,i;
	struct node *newnode,*temp;
	printf("\nEnter Position:");
	scanf("%d",&pos);
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\n*Memory is not created*\n");
		return;
	}
	printf("Enter data into node:");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=NULL;
	if(pos<1||pos>count)
	{
		printf("\n*Insertion Not Possible*");
		free(newnode);
		return;
	}
	temp=head;
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
	count++;
	printf("---Node is Inserted---\n");
}
void insert_beg()
{
	int info;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\n*Memory is not created*\n");
		return;
	}
	printf("\nEnter data into Node:");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=head;
	head=newnode;
	count++;
	printf("---Node is Added---\n");
}
void delete_beg()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	temp=head;
	head=head->next;
	free(temp);
	count--;
	printf("\n---Node is Deleted---\n");
}
void delete_end()
{
	struct node *curr,*prev;
	curr=head;
	if(head==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	while(curr->next!=NULL)
	{
		prev=curr;
		curr=curr->next;
	}
	prev->next=NULL;
	end=prev;
	free(curr);
	count--;
	printf("\n---Node is deleted---\n");
}
void delete_any_pos()
	{
		int pos,i;
		if(head==NULL)
		{
			printf("\nList is empty\n");
			return;
		}
	printf("enter position to delete");
	scanf("%d", &pos);
	struct node *temp,*prev;
	temp=head;
	for(i=1;i<pos;i++){
		prev=temp;
		temp=temp->next;
	}
	prev->next=temp->next;
	free(temp);
	count--;
	printf("Node is deleted at any pos");
}
void search()
{
	int flag=0,key;
	struct node*curr=head,*head;
	printf("Enter the element to be searched: ");
    scanf("%d", &key);
	while(curr!=NULL)
	{
		if(curr->data==key)
		{
			printf("Element found");
			flag=1;
			break;
		}
		curr=curr->next;
	}
	if(flag==0)
	{
		printf("Element not found");
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n****INDEX****\n");
		printf("1.Create\n2.Display\n3.Insert node at Beginning\n");
		printf("4.Insert node at any position\n5.Insert node at end\n");
		printf("6.Delete node at Beginning\n7.Delete node at end\n");
		printf("8.Delete any Node\n9.search an element\n10.exit");
		printf("Enter Your Choice:");
	    scanf("%d",&ch);
    	switch(ch)
    	{
		  case 1:create_nodes();break;
		  case 2:display();break;
		  case 3:insert_beg();break;
	      case 4:insert_any();break;
		  case 5:insert_end();break;
		  case 6:delete_beg();break;
		  case 7:delete_end();break;
		  case 8:delete_any_pos();break;
		  case 9:search();break;
	      case 10:exit(0);
		  default:printf("\n--Invalid choice--");
    	}
    }
    return 0;
}

