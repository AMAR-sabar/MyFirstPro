#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void frst_node_del();
int len();
void ASSENDING();
void DESSENDING();
void Node_Swap();


struct node
{
	int data;
	struct node* link;
};
struct node* head=NULL;

void create()
{
	struct node *temp, *next;

		if(head==NULL)
		{
			temp=(struct node*)malloc(sizeof(struct node));
			printf("\n\tPLEASE ENTER THE  DATA IN THE NODES. \n");
			scanf("%d",&temp->data);
			temp->link=NULL;
			if(head==NULL)
			head=temp;
		}
		else
			printf("\n\tNODE ALREADY CREATED ");
		
		
	
}

void Atbegin()
{
	struct node *temp;

		temp=(struct node*)malloc(sizeof(struct node));
		
		if(head==NULL)
		{
			printf("\n\tPLEASE, CREATE NODE FIRST ");
		}
		else
		{	printf("\n\t<---YOU ARE GOING TO ADD  NODE(S) IN  THE BEGINNING OF THE SINGLE  LINKED LIST--->\n\n");
			printf("\n\tPLEASE ENTER THE  DATA IN THE NODES. \n");
			scanf("%d",&temp->data);
			temp->link=NULL; 
			//if(temp->link==NULL)
			//{	
			
				temp->link=head;
				head=temp;
			//}
			//else
			//	printf("\n\t*****Something WRONG****");
		}
		
			
}

void loc()
{
	struct node *temp,*next;
	int loc,i=1;

		temp=(struct node*)malloc(sizeof(struct node));
		
		if(head==NULL)
		{
			printf("\n\tPLEASE, CREATE NODE FIRST ");
		}
		else
		{	printf("<---YOU ARE GOING TO ADD  NODE(S) IN THE SPRECIFIC LOCATION OF THE SINGLE  LINKED LIST--->\n\n");
			printf("\n\tPLEASE ENTER THE  LOCATION. \n");
			scanf("%d",&loc);
			 	
			next=head;
			if(len()<loc)
				printf("\n\tOUT OF RANGE");
			else
			{	while(i<loc)
				{
					next=next->link;
					i++;
				}
				printf("\n\tPLEASE ENTER THE  DATA IN THE NODES. \n");
				scanf("%d",&temp->data);
				temp->link=NULL;
				temp->link=next->link;
				next->link=temp;
			}
		}
		

}

void Atend()
{
	struct node *temp,*end;

		temp=(struct node*)malloc(sizeof(struct node));
		
		if(head==NULL)
		{
			printf("\n\tPLEASE, CREATE NODE FIRST ");
		}
		else
		{	printf("<---YOU ARE GOING TO ADD  NODE(S) INT THE END OF THE SINGLE  LINKED LIST--->\n\n");
			printf("\n\tPLEASE ENTER THE  DATA IN THE NODES. \n");
			scanf("%d",&temp->data);
			temp->link=NULL; 	
			end=head;
			while(end->link!=NULL)
				end=end->link;
			end->link=temp;
				
	
		}
		
}

void frst_node_del()
{
	struct node* temp;
	temp=head;
	
	head=temp->link;
	temp->link=NULL;
	printf("\n\t###<> FIRST NODE IS DELETED <>### ");
}

void Del_Spec_loc()
{
	int i=1,loc;
	struct node* temp,*del,*join;
	temp=head;
	printf("\n\tENTER THE LOCATION\n");
	scanf("%d",&loc);
	while(i<loc-1)
	{
		temp=temp->link;
		i++;
	}
	del=temp->link;
	join=del->link;
	del->link=NULL;
	temp->link=join;
	free(del);
	printf("\n\t###<> LOCATION %d IS DELETED <>###",loc);
	
}


void Delet_last_node()
{
	struct node* temp,*del;
	int i=1;
	temp=head;
	if(len()-1)
	{
	while(i<len()-1)
	{
		temp=temp->link;
		i++;
	
	}
	del=temp->link;
	temp->link=NULL;
	free(del);
	printf("\n\t###<> LAST NODE IS DELETED <>####");
	}
	else
		printf("\n\t###<> NO LAST NODE FOUND <>###");
}


int len()
{	
	
	int count=0;
	if(head==NULL)
		return(count);
	else
	{	struct node* len;
		len=head;
		while(len!=NULL)
		{
			len=len->link;
			count++;
		}
	}
	return(count);
}


int Traversing()
{	
	int count=1;
	struct node* temp;
	temp=head;
	if(temp!=NULL)
	{	
		printf("\v\v");		
		while(temp!=NULL)
		{
			
			printf("\tDATA IN THE NODE-->%d-->| %d |\n",count++,temp->data);
			temp=temp->link;
		
		}
			
	}
	else
 		printf("\n\t***SORRY, NO DATA FOUND!!!***\n\n");
	printf("\n\tTHE NUMBER OF NODES IN THE SINGLE LINKED LIST IS =%d\n",--count);
	return(count);
}
void Reverse_Linked()
{
	int i,j,k,swap;
	struct node* p, *q;
	i=0;
	j=len()-1;
	q=p=head;
	if(head!=NULL)
	{	while(i<j)
		{
			k=0;
			while(k<j)
			{
				p=p->link;
				k++;	
			}
			swap=p->data;
			p->data=q->data;
			q->data=swap;
			i++;
			j--;
			p=head;
			q=q->link;
		}
		printf("\n\t**---<> REVERSE OPERATION DONE <>---***");
	}
	else
		printf("\n\t#### BEFORE REVERSE OPERATION PLEASE CREATE NODES ####");
}
void Adjacent_Node_Swap()
{
	int loc,i=1;
	struct node*temp,*join,*swap;
	
	if(head!=NULL)
	{	
		printf("\n\t ENTER A LOCATION\n");
		scanf(" %d",&loc);
		temp=head;
		if(1==loc)
		{
			swap=temp->link;
			join=swap->link;
			temp->link=join;
			swap->link=temp;
			head=swap;
			printf("\n\t---><> NODE SWAP DONE <><--- ");
		}
		else
		{	while(i<loc-1)
			{
				temp=temp->link;
				i++;
			}
			swap=temp->link;
			join=swap->link;
			temp->link=join;
			swap->link=join->link;
			join->link=swap;
			printf("\n\t---><> NODE SWAP DONE <><--- ");
		}
	}
	else
	printf("\n\t#### BEFORE SWAPPING OPERATION PLEASE CREATE NODES ####");
}

void ASSENDING()
{
	int i=1, swap, data;
	struct node* temp, *A;
	temp=A=head;
	while(i<len())
	{
		while(temp!=NULL)
		{
			if(A->data>temp->data)
			{
				swap=A->data;
				A->data=temp->data;
				temp->data=swap;
			}
			temp=temp->link;
		}
		A=A->link;
		temp=A->link;
		i++;
	
	}
	printf("\v\v\t####<> SORTING DONE <>####");

}

void DESSENDING()
{
	int i=1, swap, data;
	struct node* temp, *A;
	temp=A=head;
	while(i<len())
	{
		while(temp!=NULL)
		{
			if(A->data<temp->data)
			{
				swap=A->data;
				A->data=temp->data;
				temp->data=swap;
			}
			temp=temp->link;
		}
		A=A->link;
		temp=A->link;
		i++;
	
	}
	printf("\v\v\t####<> SORTING DONE <>####");

}



int linked()
{
	int i, choice,stop,sel;
	char ch;
	printf("\t\t****OPERATIONS IN THE LINKED LIST*****\n\t****please enter the choice****\n\t1. ---> CREATE LINKED LIST\n\t2. ---> ADDING NODES\n\t3. ---> DELETINH NODE\n\t4. ---> NUMBER OF THE NODES IN THE LINKED LIST\n\t5. ---> TRAVERSING IN THE LIST\n\t6. ---> SORTING THE LIST\n\t7. ---> REVERSE SINGLE LINKED LIST\n\t8. --->  ADJACENT NODE SWAP\n\t");
		scanf("%d",&choice);
		
		
			
			if(choice==1)
			{
			printf("<---YOU ARE GOING TO CREATE SINGLE  LINKED LIST--->\n\n");
			//printf("\t****Enter the length of the linked list :****\n\n");
			//scanf("%d",&len);
			//for(i=1;i<=len;i++)
				create();
			}
			else if(choice==2)
			{
				printf("\n\tINSERTING OPERATIONS NODES IN THE SINGLE LINKED LIST:\n\t1.--> ADD IN THE BEGINNING?\n\t2.--> ADD IN THE SPECIFIC LOCATION?\n\t3.--> ADD IN THE LAST NODE?\n\n");
				scanf("%d",&sel);
				if(sel==1)
				{	
					
					Atbegin();
				}
				else if(sel==2)
				{
					
					loc();
				}
				else if(sel==3)
				{	
					
					Atend();
				}
				else
					printf("\n\t*--->WRONG CHOICE<---*");
				
			}
			else if(choice==3)
			{
				printf("\n\tDELETE OPERATIONS IN THE SINGLE LINKED LIST:\n\t1.--> DELETING FIRST NODE IN THE SINGLE LINKED LIST\n\t2.-->DELETING SPECIFIC LOACTION\n\t3.DELETING LAST NODE IN THE SINGLE LINKED LIST\n\n");
				scanf("%d",&sel);
				if(sel==1)
				{	
					
					frst_node_del();
				}
				else if(sel==2)
				{	
					
					Del_Spec_loc();
					
				}
				else if(sel==3)
				{	
					Delet_last_node();
					
				}
				else
					printf("\n\t*--->WRONG CHOICE<---*");
			}				
				
			else if(choice==4)
				 {
				 	printf("\n\tTHE NUMBER OF NODES IN THE SINGLE LINKED LIST IS =%d\n",len());
				 }
	
			else if(choice==5)
		   		 Traversing();
			
			else if(choice==6)
			{
				int sort;				
				printf("1. ---> ASSENDING ORDER.\n\t2. --->DESSENDING ORDER.");
				scanf("%d",&sort);
				if(sort==1)
					ASSENDING();
				else if(sort==2)
					DESSENDING();
				else
					printf("\n\t*--->WRONG CHOICE<---*");
						
			} 
			
			else if(choice==7)
				Reverse_Linked();
		 	else if(choice==8)
				 Adjacent_Node_Swap();
			else
			printf("\n\t*--->WRONG CHOICE<---*");
	
}


 
int main()
{	char stop;
	
		do
		{
			linked();
			printf("\v\v\v\n\t***YOU WANT TO SEE OPTIONS***\n\t\tYES---> Y\\y ?\n\t\t    OR \n\t\tEXIT---> N\\n ?\n");
			scanf(" %c",&stop);
		}while(stop=='Y'|| stop=='y');
			
		
	
}





