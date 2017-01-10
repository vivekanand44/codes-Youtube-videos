#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

void find_middle(node *p)
{
	node *q = p;
	if(p)
	{
		if(p->next == NULL)
			{
				printf("\n Middle node is  %d", p->data);
			}
		else
		{
			while(p && p->next)
			{
				q = q->next;
				p = p->next->next;
			}
			
			printf("\n Middle node is  %d", q->data);			
			
		}
	}
}

int main()
{	
	int a , i , n , cnt , r;
	node *p,*q,*start , *temp , *new_start;
	printf("Enter the number of nodes");
	scanf("%d",&n);
	
	printf("Enter all the nodes separated by space \n");
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

find_middle(start);

}
