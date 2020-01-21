// Simple Queue by using Simple Array and looping
#include<stdio.h>
#define size 5
int Q[size];
int front=0;
int rear=0;

void En_Q()
{ 
	if(rear==size)
		printf(" OVERFLOW \n");
	else
	{
		printf(" ENTER A DATA IN AN QUEUE\n");
 		scanf("%d",&Q[rear]);
		if(rear<size)	
		   rear++;
		
	}
	
}
void De_Q()
{
	if(Q[front]==NULL)
		printf(" QUEUE IS EMPTY	\n");
	else
	{
		printf("DELETE=|%d|\n",Q[front]);
		for(int i=front;i<rear;i++)
		{
			Q[i]=Q[i+1];
			
		}
		rear--;
	}
}
void Front()
{
	
	if(Q[front]==NULL)
		printf(" QUEUE IS EMPTY\n");
	else 
		printf("Front=%d\n",Q[front]);
}
void Rear()
{
	if(Q[front]==NULL)
		printf(" QUEUE IS EMPTY\n");
	else if(front==rear-1)
		printf("Rear=%d\n",Q[rear-1]);
	else
		printf("REAR=%d\n",Q[rear-1]);
}
void Display()
{
	for(int i=0; i<rear;i++)
		printf("|%d|",Q[i]);
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
