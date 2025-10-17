//stack implementation using arrays
#include<stdio.h>
#include<stdlib.h>
#define size 5
//global declaration
int stack[size],top=-1;
//functuion protypes
void push(int);
int pop();
int peek();
void display();
void push(int ele)
{
	if(top==size-1)
	{
		printf("stack is overflow\n");
	}
	else
	{
		top++;//top=top+1;
		stack[top]=ele;
	}
	printf("Element is inserted");
}
int pop()
{
	int x;
	if(top==-1)
	{
		printf("underflow");
        return 0;
	}
	else
	{
		x=stack[top];
		top--;
	}
	return x;
}
int peek()
{
	int x;
	if(top==-1)
	{
		printf("empty");
	}
	else
	{
		x=stack[top];
	}
	return x;
}
void display()
{
	if(top==-1)
	{
		printf("stack is empty");
	}
	else
	{
		int i;
		printf("stack elements are\n");
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}
int main()
{
	int ch,x;
	do
	{
		printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter element :");
			        scanf("%d",&x);
			        push(x);
			        break;
			case 2:x=pop();
			      printf("popped element is %d\n",x);
			      break;
			case 3: x=peek();
			       printf("tht top most element is %d\n",x);
			       break;
			case 4:display();
			     break;
	        case 5:printf("Thank you....");
	             break;
	        default :printf("Invalid choice\n");     
		}
	}while(ch!=5);
	return 0;
}
