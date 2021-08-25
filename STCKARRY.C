#include<stdio.h>
#include<conio.h>
#define max 10
int stack[max],top=-1;
int push();
int pop();
int peek();
int display();
int main(void)
{
	int ch;
	clrscr();
	do
	{
		printf("\tEnter the option\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. PEEK\n");
		printf("4. DISPLAY\n");
		printf("5.EXIT\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: peek();
				break;
			case 4: display();
				break;
		}
	}
	while(ch!=5);
	return 0;
}
	int push()
	{
		int item;
		if(top==max-1)
			printf("OVERFLOW");
		else
		{
			printf("Enter the element to push:");
			scanf("%d",&item);
			top=top+1;
			stack[top]=item;
		}
		return 0;
	}
	int pop()
	{
		int val;
		if(top==-1)
			printf("UNDERFLOW");
		else
		{
			val=stack[top];
			top=top-1;
			printf("Popped element is %d",val);
		}
		return 0;
	}
	int peek()
	{
		if(top==-1)
			printf("Stack is empty");
		else
			printf("Top element is %d",stack[top]);
		return 0;
	}
	int display()
	{
		int i;
		if(top==-1)
			printf("Stack is empty\n");
		else
		{
			printf("\tStack\n");
			for(i=0;i<=top;i++);
			{
				printf("%d\t",stack[i]);
			}
		}
		return 0;
	}
	getch();
