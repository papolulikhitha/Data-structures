#include <stdio.h>
#include <stdlib.h>
struct node *head = NULL, *end = NULL;
int count = 0;
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *create()
{
    int info;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL){
        printf("----Memory allocation failed----\n");
        return NULL;
    }
    printf("\nEnter data into a node: ");
    scanf("%d", &info);
    newnode->data = info;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}
void create_list()
{
    struct node *newnode;
    newnode = create();
    if (newnode == NULL){
        return;
    }
    if (head == NULL){
        head = end = newnode;
    }
    else{
        end->next = newnode;
        newnode->prev = end;
        end = newnode;
    }
    count++;
    printf("\n----Node is created----\n");
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty!");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
}
void insert_beg()
{
    struct node *newnode;
    newnode = create();
    if (newnode == NULL){
        return;
    }
    if (head == NULL){
        head = end = newnode;
    }
    else{
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    count++;
    printf("\n----Node is Added----\n");
}

void insert_end()
{
    struct node *newnode;
    newnode = create();
    if (newnode == NULL){
        return;
    }
    if (head == NULL){
        head = end = newnode;
    }
    else{
        end->next = newnode;
        newnode->prev = end;
        end = newnode;
    }
    count++;
    printf("\n----Node is Added----\n");
}
void insert_any()
{
    int pos,i;
    printf("\nEnter Position: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > count + 1){
        printf("\n*Invalid Position*\n");
        return;
    }
    if (pos == 1){
        insert_beg();
        return;
    }
    if (pos == count + 1){
        insert_end();
        return;
    }
    struct node *newnode = create();
    if (newnode == NULL) 
    {
    	return;
	}
    struct node *temp = head;
    for ( i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
    count++;
    printf("---Node is Added---\n");
}
void delete_beg()
{
	struct node *temp;
	temp=head;
	head=head->next;
	if(head==NULL){
		end=NULL;
	}
	else{
		head->prev=NULL;
	}
	free(temp);
	count--;
	printf("\n----Node is deleted----\n");
}
void delete_end()
{
		struct node *temp;
	temp=end;
	end=end->prev;
	if(end==NULL){
		head=NULL;
	}
	else{
		end->next=NULL;
	}
	free(temp);
	count--;
	printf("\nNode is deleted\n");
}

void delete_any()
{
	int pos,i;
	struct node *temp,*curr;
	if(head==NULL)
	{
		printf("List is Empty\n");
		return;
	}
	printf("Enter position: ");
	scanf("%d",&pos);
	if(pos==1)
	{
		delete_beg();
		return;
	}
	else if(pos==count)
	{
		delete_end();
		return;
	}
	else
	{
	curr=head;
	for(i=1;i<pos;i++)
	{
		temp=curr;
		curr=curr->next;
	}
	temp->next=curr->next;
	curr->next->prev=temp;
	free(curr);
	count--;
	printf("node is deleted any pos ");
}
}

void search()
{
	struct node *curr=head;
	int key,flag=0;
	if(head==NULL){
		printf("List is empty");
		return;
	}
	printf("Enter element to be searched:");
	scanf("%d",&key);
	while(curr!=NULL)
	{
		if(curr->data==key)
		{
			printf("\n----Element Found----\n");
			flag=1;
			break;
		}
		curr=curr->next;
	}
	if(flag==0)
	printf("----Element not found----\n");
}
int main()
{
    int ch;
    printf("---Index---\n");
    printf("\n1. Create list\n2. Display \n3. Insert node at beginning\n4. Insert node at end\n");
    printf("5. Insert node at any position\n6.Delete first node\n7.Delete last node\n8.Delete any node\n9.Search an element\n10.count\n11.Exit\n");
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create_list();break;
        case 2:
            display();break;
        case 3:
            insert_beg();break;
        case 4:
            insert_end();break;
        case 5:
            insert_any();break;
        case 6:
            delete_beg();break;
        case 7:
        	delete_end();break;
        case 8:
        	delete_any();break;
        case 9:
        	search();break;
        case 10:
        	printf("\nCount : - %d -\n",count);break;
        case 11:
        	printf("\nExiting\n");
        	exit(0);
        default:
            printf("Invalid choice\n");break;
        }
    }
    return 0;
}
