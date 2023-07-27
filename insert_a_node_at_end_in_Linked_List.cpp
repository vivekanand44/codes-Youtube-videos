#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;  
	struct node *next;
}node;

node* insert_node_at_end(int node_value , node* start)
{
	node *new_node , *p;
	new_node = (node*)malloc(sizeof(node));
	new_node->data = node_value;
	new_node->next = NULL;

	p = start;
	while(p->next !=NULL)
	{
		p = p->next;
	}

	p->next = new_node;

	return start;
}

int main()
{	
	int a , i = 1 , n ,r , node_data , position , node_value;     //   i = 0  is also ok....
	node *p,*q,*start;
	printf("Enter the number of nodes");
	scanf("%d",&n);
	
	printf("Enter node %d  \n",i);   //  you can also start with i = 0
	p = (node*)malloc(sizeof(node));
	scanf("%d",&a);
	p->data = a;
	p->next = NULL;
	start = p; 
		
	for(i=2;i<=n;i++)                //if i=0 , then for ( i = 1; i < n; i++ )
	 	{
	 		printf("Enter node %d  \n",i);
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
		printf("\t %d", p->data);
		p = p->next;
	}

	printf("\nEnter the value of the node which you want to insert at end");
	scanf("%d",&node_value);


	start = insert_node_at_end(node_value , start);


	printf("\n");
	p = start;
	while(p!=NULL)
	{
		printf("\t %d",p->data);
		p = p->next;
	}	



	
return 0;
}