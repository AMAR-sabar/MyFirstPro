#include<stdio.h>
#include<stdlib.h>
void After_node();
int len();
void Del_First_Node();	
void Del_Spec_Node();
void Del_Last_Node();
void At_end();
void Reverse();



struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

struct node* head=NULL;


void create()
{
	
	if(head==NULL)
	{
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		printf("ENTER THE DATA IN THE NODE :\n\n");
		scanf("%d",&temp->data);
		temp->next=temp->prev=NULL;
		head=temp;
		printf("<@> FIRST NODE CREATED <@>\n\n");
	}
	else
	{
		At_end();
	}
}

void At_beginning()
{
	
	if(head!=NULL)
	{	
		struct node* front, *temp=(struct node*)malloc(sizeof(struct node));
		printf("ENTER THE DATA IN THE NODE\n\n");
		scanf("%d",&temp->data);
		temp->next=temp->prev=NULL;
		front=head;
		front->prev=temp;
		temp->next=front;
		head=temp;
		
		printf("@@@ NODE ADDED AT THE BEGINNING @@@\n\n");
	}
	else
	  create();
}


void At_end()
{
	if(head==NULL)
	{
		create();
	}
	else
	{	
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		printf("ENTER THE DATA IN THE NODE :\n\n");
		scanf("%d",&temp->data);
		temp->next=temp->prev=NULL;
		struct node* link;
		link=head;
		while(link->next!=NULL)
		{
			link=link->next;
		}
		link->next=temp;
		temp->prev=link;
		printf("<@> NODE ADDED IN THE LAST OF THE LIST <@>\n\n");
	}

}

void Before_node()
{
	if(head==NULL)
			create();
	else
	{
		int loc, i=1;
		printf("<> ENTER A LOCATION <>\n\n");
		scanf("%d",&loc);
		if(loc>len())
		{
			printf(" <> Oooppsss!!! INVALID LOCATION <>\n\n");
		}
		
		else if(loc==1)
				At_end();
			
		else
		{
			struct node* add, *temp=(struct node*)malloc(sizeof(struct node));
			printf("ENTER THE DATA IN THE NODE :\n\n");
			scanf("%d",&temp->data);
			temp->next=temp->prev=NULL;
			add=head;
			while(i<loc)
			{
				add=add->next;
				i++;
			}
			
			add->prev->next=temp;
			temp->prev=add->prev;
			temp->next=add;
			add->prev=temp;
			printf("<@> NODE ADDED <@>\n\n");
		 }
	}	 


}

void After_node()
{
	if(head==NULL)
		create();
	else
	{
		int loc, i=1;
		printf("<> ENTER A LOCATION <>\n\n");
		scanf("%d",&loc);
		if(loc>len())
		{
			printf(" <> Oooppsss!!! INVALID LOCATION <>\n\n");
		}
		else if(1==loc)
				At_beginning();
		else
		{
			struct node* add, *temp=(struct node*)malloc(sizeof(struct node));
			printf("ENTER THE DATA IN THE NODE :\n\n");
			scanf("%d",&temp->data);
			temp->next=temp->prev=NULL;
			add=head;
			while(i<loc)
			{
				add=add->next;
				i++;
			}
			temp->next=add->next;
			add->next->prev=temp;
			add->next=temp;
			temp->prev=add;
			printf("<@> NODE ADDED <@>\n\n");
		 }
	}	 
}

int len()
{
	int count=0;
	struct node* temp=head;
			while(temp!=NULL)
			{
				count++;
				temp=temp->next;
			}
	return(count);
}

void Traversing()
{
	int i=1;
	struct node* temp=head;
	if(temp==NULL)
			printf("\n\n<@@>DOUBLY LINKED LIST IS EMPTY<@@>");
	else
		{	
			printf("\n\t\t<<<<<----------------DATA--------------------->>>>>");
			while(temp!=NULL)
			{
				printf("\nNODE-->%d--> | %d |",i,temp->data);
				temp=temp->next;
				i++;
			}
		}

}

void Del_First_Node()
{
	int loc;
	char yes;
	printf("<@@@> ARE YOU SURE TO DELETE FIRST NODE, Y\\N ? <@@@>\n\n");
	scanf(" %c",&yes);
	if(yes=='Y'||yes=='y')
	{
		struct node* temp=head;
		head=temp->next;
		head->prev=NULL;
		temp->next=NULL;
		free(temp);
		printf("<@@@> FIRST NODE DELETED <@@@>\n\n");

	}
	else 
	{
		printf("<@@@> ABORTED <@@@>\n\n");
	}
}


void Del_Spec_Node()
{
	int loc,i=1;
	char yes;
	printf("<@@@> ARE YOU SURE TO DELETE THE NODE, Y\\N ? <@@@>\n\n");
	scanf(" %c",&yes);
	if(yes=='Y'||yes=='y')
	{
		printf("<@@@> ENTER LOCATION <@@@>\n\n");
		scanf("%d",&loc);
		struct node* temp=head, *del;
			
		if(loc==1)
			Del_First_Node();
		
		else if(loc==len())
			Del_Last_Node();
		else
		{
			while(i<loc-1)
			{
				temp=temp->next;
			 	i++;
			}
				del=temp->next;
				del->next->prev=temp;
				temp->next=del->next;
				del->next=del->prev=NULL;
				free(del);
				printf("<@@@> SPECIFIC NODE DELETED <@@@>\n\n");
			}
		
	}
	else 
	{
		printf("<@@@> ABORTED <@@@>\n\n");
	}
}

void Del_Last_Node()
{
	int loc,i=1;
	char yes;
	printf("<@@@> ARE YOU SURE TO DELETE THE LAST NODE, Y\\N ? <@@@>\n\n");
	scanf(" %c",&yes);
	if(yes=='Y'||yes=='y')
	{
		struct node* temp=head, *del;
		while(i<len()-1)
		{
			temp=temp->next;
			i++;
		}
		del=temp->next;
		temp->next=NULL;
		del->prev=NULL;
		free(del);
		printf("<@@@> LAST NODE DELETED <@@@>\n\n");
	}
	else 
	{
		printf("<@@@> ABORTED !!! <@@@>\n\n");
	}
}


void Reverse()
{
	int i=0,j=len()-1,k,swap;
	struct node* temp, *ptr;
	temp=ptr=head;
	if(head!=NULL)
	{
		while(i<j)
		{
			k=0;
			while(k<j)
			{
				temp=temp->next;
				k++;
			}
			swap=temp->data;
			temp->data=ptr->data;
			ptr->data=swap;
			temp=head;
			ptr=ptr->next;
			i++;
			j--;
		}
		printf("<@@@> REVERSE OPERATION DONE <@@@>\n\n");
	}
	else
		printf("\n\t<####>---BEFORE REVERSE OPERATION PLEASE CREATE NODES---<####>\n\n");
}

void Descen_Order()
{
	

}

int linked()
{
			int i, choice,del,sel;
			char ch;
			printf("\t\t****OPERATIONS IN THE DOUBLY LINKED LIST*****\n\t****please enter the choice****\n\t1. ---> CREATE DOUBLY LINKED LIST\n\t2. ---> ADDING NODES\n\t3. ---> DELETING NODE\n\t4. ---> NUMBER OF THE NODES IN THE DOUBLY LINKED LIST\n\t5. ---> TRAVERSING (DISPLAYING) IN THE DOUBLY LINKED LIST\n\t6. ---> SORTING THE  DOUBLY LINKED LIST\n\t7. ---> REVERSE DOUBLY LINKED LIST\n\t8. ---> ADJACENT NODE SWAP\n\t9. ---> MERGING OPERATIONS\n\t");
			scanf(" %d",&choice);
		
			if(choice==1)
			{
				
				create();
			}
			else if(choice==2)
			{
							printf("\n\tINSERTING OPERATIONS NODES IN THE DOUBLY LINKED LIST:\n\t1.--> ADD IN THE BEGINNING?\n\t2.--> ADD AFTER THE GIVEN NODE?\n\t3.--> ADD BEFORE THE GIVEN NODE\n\t4.--> ADD IN THE LAST NODE?\n\n");
				scanf("%d",&sel);
				
			   if(sel==1)
				{	
					At_beginning();
				}
				else if(sel==2)
				{
						 After_node();
				}
				else if(sel==3)
				{
					Before_node();
				}
				else if(sel==4)
				{	
					
					At_end();
				}
				else
					printf("\n\t*--->WRONG CHOICE<---*");
			}
			
			else if(choice==3)
			{	
				
				printf("\n\tDELETE OPERATIONS IN THE DOUBLY LINKED LIST:\n\t1.--> DELETING FIRST NODE IN THE DOUBLY LINKED LIST\n\t2.--> DELETING SPECIFIC LOCATION\n\t3.--> DELETING LAST NODE IN THE SINGLE LINKED LIST\n\n");
				
				scanf("%d",&del);
				
				if(del==1)	
						 Del_First_Node();
				else if(del==2)
						Del_Spec_Node(); 
				else if(del==3)
						Del_Last_Node();
				else
					printf("<###> INVALID INPUT <###>\n\n");
			} 
				
			
				
			else if(choice==4)
				printf("\n\tTHE NUMBER OF NODES IN THE DOUBLY LINKED LIST IS =%d\n",len());
			else if(choice==5)
				Traversing();
			else if(choice==6)
			{
				int sort;				
				printf("1. ---> ASCENDING ORDER.\n\t2. --->DESCENDING ORDER\n.");
				scanf("%d",&sort);
				if(sort==1)
					Ascend_Order();
				else if(sort==2)
					Descend_Order();
				else
					printf("\n\t*--->WRONG CHOICE<---*");
						
			}
		   else if(choice==7)
		   	Reverse();	 
		 

}
 
int main()
{		
		char stop;
		while(1)
		{	
			printf("\v\v\v\n\t***YOU WANT TO SEE OPTIONS***\n\t\tYES---> Y\\y ?\n\t\t    OR \n\t\tEXIT---> N\\n ?\n");
			scanf(" %c",&stop);
			if(stop=='Y'|| stop=='y')	
						linked();
			else if(stop=='N'||stop=='n')
						break;
			else
				printf("\n\n<-----------> INVALID  INPUT <------------>\n\n");
		}	
}
