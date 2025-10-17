#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
	int data;
	struct stack *next;
}STACK;
STACK *top=NULL;
int count=0;
void push(int);
int pop();
int peek();
int display();
void push(int info)
{
		STACK *newnode=(STACK*)malloc(sizeof(STACK));
		if(newnode==NULL)
		{
			printf("Memory not allocated");
			return;
		}
		newnode->data=info;
		newnode->next=NULL;
		if(top==NULL)
		top=newnode;
		else
		{
			newnode->next=top;
			top=newnode;
		}
		count++;
		printf("%d is pushed to stack\n",info);
	}
	int pop()
	{
		int x;
		if(top==NULL)
		printf("Stack is underflow\n");
		else
		{
			STACK *temp=top;
			top=top->next;
			x=temp->data;
			count--;
			free(temp);
			return x;
		}
	}
	int peek()
	{
		if(top==NULL)
		printf("Stack is empty");
		else
		return top->data;
	}
	int display()
	{
		if(top==NULL)
		printf("Stack is empty\n");
		else
		{
			STACK *temp=top;
			printf("\n***Stack elements are***\n");
			while(temp!=NULL)
			{
				printf("\t%d\n",temp->data);
				temp=temp->next;
			}
		}
	}
int main()
{
	int ch,x;
	do
	{
		printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				    printf("\nEnter element: ");
				    scanf("%d",&x);
				    push(x);
				    break;
			case 2:
			       pop(x);
				    printf("popped element is %d\n",x);
			      break;
			case 3: x=peek();
			       printf("the top most element is %d\n",x);
			       break;
			case 4:display();
			     break;
	        case 5:printf("Thank you!!!!");
	             break;
	        default :printf("Invalid choice\n");     
		}
	}while(ch!=7);
	return 0;
}
