#include<stdio.h>
#include<stdlib.h>
struct node
     {
	int data;
	struct node *next;
    };
    struct node*head=NULL,*end=NULL;
    int count=0;
    void insert_beg();
    void display();
    void insert_beg()
{
	int info;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("memory not created");
		return ;
	}
	printf("/n enter data into node:");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=NULL;
	newnode->next=head;
	head=newnode;
	count++;
	printf("/nnode is added:");
}
	void display()
{
	struct node*temp;
	if(head==NULL)
	{
		printf("\nlist is empty");
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
}
int main()
{
		int choice;
	
    while(1) 
	{
        printf("\nMenu:\n");
        printf("1. insert_beg\n");
        printf("2. Display List\n");
        printf("3. count node\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) 
		{
            case 1: insert_beg(); break;
            case 2: display(); break;
           case 3:printf("\n no.of nodes are:%d",count);break;
			case 4:exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
