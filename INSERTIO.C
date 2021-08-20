#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node * next;
}node;
node * create(int);
node * insert_beg(node *start);
node * insert_end(node *start);
node * insert_after(node *start);
node * delete_beg(node *start);
node * delete_end(node *start);
node * delete_node(node *start);
void display(node*start);
int main()
{
	int n,ch;
	node*start=NULL;
	clrscr();
	do
	{
		printf("\tMain Menu\n");
		printf("1. Create a list\n");
		printf("2. Display the list\n");
		printf("3. Add a note at the begining\n");
		printf("4. Add a note at the end\n");
		printf("5. Add a node after a given node\n");
		printf("6. Delete a node from the begining\n");
		printf("7. Delete a node from the end\n");
		printf("8. Delete a given node\n");
		printf("9. Exit\n");
		printf("\tEnter the option\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("How many nodes:");
				scanf("%d",&n);
				start=create(n);
				break;
			case 2: display(start);
				break;
			case 3: start=insert_beg(start);
				break;
			case 4: start=insert_end(start);
				break;
			case 5: start=insert_after(start);
				break;
			case 6: start=delete_beg(start);
				break;
			case 7: start=delete_end(start);
				break;
			case 8: start=delete_node(start);
				break;
		}
	}
	while(ch!=9);
	getch();
	return 0;
}
node *create(int n)
{
	int i;
	node *start=NULL;
	node *newnode=NULL;
	node *ptr=NULL;
	for(i=0;i<n;i++)
	{
		newnode=(node*)malloc(sizeof(node));
		printf("Enter the data for node no. %d:",i+1);
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(start==NULL)
			start=newnode;
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=newnode;
		}
	}
	return start;
}
void display(node *start)
{
	node *ptr=start;
	while(ptr!=NULL)
	{
		printf("\t-->",ptr->data);
		ptr=ptr->next;
	}
}
node * insert_beg(node *start)
{
	node *new_node;
	int item;
	printf("Enter data:");
	scanf("%d",&item);
	new_node=(node*)malloc(sizeof(node));
	new_node->data=item;
	new_node->next=start;
	start=new_node;
	return start;
}
node * insert_end(node *start)
{
	node *new_node;
	node *ptr;
	int item;
	printf("Enter data:");
	scanf("%d",&item);
	new_node=(node*)malloc(sizeof(node));
	new_node->data=item;
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->next=NULL;
	return start;
}
node * insert_after(node *start)
{
	node *new_node;
	node *ptr;
	node *preptr;
	int item,val;
	printf("Enter data:");
	scanf("%d",&item);
	printf("Enter the value to insrert after the node:");
	scanf("%d",&val);
	new_node=(node*)malloc(sizeof(node));
	new_node->data=item;
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
}
node * delete_beg(node *start)
{
	node *ptr;
	ptr=start;
	start=start->next;
	free(ptr);
	return start;
}
node * delete_end(node *start)
{
	node *ptr,*preptr;
	ptr=start;
	while(ptr->next!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
	return start;
}
node * delete_node(node *start)
{
	node *ptr;
	node *preptr,*temp;
	int val;
	printf("\nEnter the data:");
	scanf("%d",&val);
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	temp=ptr;
	preptr->next=ptr->next;
	free(temp);
	return start;
}
