// SIMPLE QUEUE BY USING SINGLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>

struct Q
{
	int data;
	struct Q* link;
};

struct Q* front=NULL;
struct Q* rear=NULL;

void EnQ()
{ 
	struct Q* temp=(struct Q*)malloc(sizeof(struct Q));
	printf(" ENTER A DATA IN AN QUEUE\n\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(front==NULL)
		front=rear=temp;
	else
	{
		rear->link=temp;
		rear=temp;
	}
}

void DeQ()
{	
	struct Q* temp=front;
	if(front==NULL)
	{
		printf(" UNDERFLOW\n");
		free(temp);
	}
	else
	{
		printf(" DELETED=%d",front->data);
		front=front->link;
		temp->link=NULL;
		free(temp);
	}
	
}
void Front()
{
	if(front==NULL)
		printf(" EMPTY QUEUE \n");
	else
	{
		printf("FRONT=%d\n\n",front->data);
	}
}
void Rear()
{
	if(front==NULL)
		printf(" EMPTY QUEUE \n");
	else
	 	printf("REAR=%d\n\n",rear->data);
}

void Display()
{
	struct Q* temp=front;
	while(temp!=NULL)
	{
		printf("%d--->",temp->data);
		temp=temp->link;
	}
}
int main()
{
	int sel;
	char yes;
	do
	{
		printf("1--> ENQUEUE.\n2--> DEQUEUE.\n3--> STATUS\n");
		scanf("%d",&sel);
		switch(sel)
		{
			case 1: EnQ();
			 break;
			 case 2: DeQ();
			 break;
			 case 3:
			 		{	Front();
			 			Rear();
			 			Display();
					 }
			 break;
			default: printf("WRONG INPUT\n");
			
		}
		while(1)
			{
				printf("\n\n OPTIONS ????\n\n\t <Y\\N>?\n");
				scanf(" %c",&yes);
				if((yes=='Y' || yes=='N')||(yes=='y' || yes=='n'))
				 break;
				else
				printf("********WRONG CHOICE*********\n");
			}
	}while(yes=='Y'||yes=='y');
}




