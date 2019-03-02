#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

int main()
{	
	int a , i = 1 , n ,r;     //   i = 0  is also ok....
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

	p->next = start;   // connect last node to first(start) node
	
	printf("\t %d", start->data);
	
	p = start->next;
	while(p!=start)
	{
		printf("\t %d", p->data);
		p = p->next;
	}

}
