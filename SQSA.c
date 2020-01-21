// Simple Queue by using Simple Array
#include<stdio.h>
#define size 5
int Q[size];
int front=-1;
int rear=-1;

void En_Q()
{ 
	int data;
	printf(" ENTER A DATA IN AN QUEUE\n");
 	scanf("%d",&data);
	if(rear==size-1)
		printf(" QUEUE IS FULL\n");
	else if(front==-1)
	{
		rear=front=0;
		Q[rear]=data;
	}
	else
	{
		rear++;
		Q[rear]=data;
		
	}
	
}
void De_Q()
{
	if((front==-1)||(front>rear))
		printf(" QUEUE IS EMPTY	\n");
	else if(front==rear)
			rear=front=-1;
	else
	{
		printf("Delete=%d\n",Q[front]);
		Q[front]=(int)NULL;
		++front;
	}
}
void Front()
{
	
	if(front==-1)
		printf(" QUEUE IS EMPTY\n");
	printf("Front=%d\n",Q[front]);
}
void Rear()
{
	if(front==-1)
		printf(" QUEUE IS EMPTY\n");
	printf("Rear=%d\n",Q[rear]);
}
void Display()
{
	int ele=front;
	if(front==-1)
		printf("QUEUE IS EMPTY\n");
	else 	
	while(ele<=rear)
	{
		printf("|%d|",Q[ele]);
		ele++;
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
			case 1: En_Q();
			 break;
			 case 2: De_Q();
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
