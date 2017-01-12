#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int a;
	struct node *next;
}node;

void check_even_odd_length(node *start)
{
	node *p;
	p = start;
	while(1)
	{
		if(p == NULL)
		{
			printf("Even");
			break;
		}
		
		if(p->next == NULL)
		{
			printf("odd");
			break;
		}
		
		p = p->next->next;
	}
	
}

int main()
{
	node *p , *q, *r , *start;
	int i , n , nt;
		
	printf("Enter the number of nodes");
	scanf("%d",&n);
	
	printf("Enter the nodes \n");
	p = (node*)malloc(sizeof(node));
	scanf("%d",&p->a);
	p->next = NULL;
	q = p;
	start = p;
	for(i=1;i<n;i++)
	{
		p = (node*)malloc(sizeof(node));
		scanf("%d",&p->a);
		p->next = NULL;
		q->next = p;
		q = q->next;			
	}
	
	check_even_odd_length(start);
}
