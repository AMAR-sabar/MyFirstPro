#include<stdio.h> 
#include<stdlib.h> 
#define max 6
  
int k=1;
struct node 
{ 
    int numE; 
    int array[max]; 
    struct node *next; 
}; 
  
  struct node* head=NULL;
  
  void create()
  {
  		int i;
  		
  		struct node* temp;
  		temp=(struct node*)malloc(sizeof(struct node));
  		temp->numE=5;
  		
  			for(i=0;i<temp->numE;i++)
  			{
  				printf("Enter the data  array[%d]
  				\n",i);
  				scanf("%d",&temp->array[i]);
  			}
				temp->next=NULL;
	
		if(head==NULL)
		{
		   head=temp;		   
		   printf("NODE : %d \n",k++);
		 }
		 else
		 {
		 	struct node* link=head;
		 	while(link->next!=NULL)
		 	{
		 		link=link->next;
		 		
		 	}
		 	link->next=temp;
		 	printf("NODE : %d\n",k++);
		 }
  
  }
  
  
void display()
{
	int j=1;
	struct node* temp=head;
	
	temp->numE=5;
	while(temp!=NULL)
	{	
		printf(" NODE : %d\n",j++);
		for(int i=0;i<temp->numE;i++)
		{
			printf("DATA in NODE-->%d-->\n",temp->array[i]);
		}
		temp=temp->next;
	}


}
int main()
{
  		int i;
  		for(i=0;i<max;i++)
  		{
  			create();
  		}
  		
  		display();
  
}
