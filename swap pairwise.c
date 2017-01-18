#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;


int main()
{
	int a , i , n;
	node *p,*q , *start ,*temp;
	printf("Enter the number of nodes");
	scanf("%d",&n);
	
	p = (node*)malloc(sizeof(node));
	scanf("%d",&a);
	p->data = a;
	p->next = NULL;
	start = p; 
		
	for(i=1;i<n;i++)
	 	{
		 	q = (node*)malloc(sizeof(node));
			scanf("%d",&a);
			q->data = a;
			q->next = NULL;			 	
		 	p->next = q;
		 	p = p->next;		 	
	 	
		}
	
	p = start;
	while(p!=NULL)
	{
		printf("%d  ",p->data);
		p = p->next;
	}
	
	//swapping code
	p = start;
	start = p->next;
	while(1)
	{
	q = p->next;
	temp = q->next;
	q->next = p;
	
	if(temp == NULL)
	{
		p->next = NULL;
		break;
	}
	
	if(temp->next == NULL)
	{
		p->next = temp;
		break;		
	}
	
	p->next = temp->next;
	p = temp;
	
	}
// print the swapped list	
	printf("\n swapped list = ");
	p = start;
	while(p!=NULL)
	{
		printf("%d  ",p->data);
		p = p->next;
	}
	
return 0;	
}
