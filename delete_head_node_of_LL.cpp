#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;  
	struct node *next;
}node;


node* delete_head_node(node *head)
{
	node* p;
	if (head->next !=NULL)
	{
		p = head;
		head = p->next;
		free(p);
	}
	else
	{
		free(head);
		head = NULL;
	}

	return head;

}



int main()
{	
	int a , i = 1 , n ,r , node_data , position;     //   i = 0  is also ok....
	node *p,*q,*head;
	printf("Enter the number of nodes");
	scanf("%d",&n);
	
	printf("Enter node %d  \n",i);   //  you can also start with i = 0
	p = (node*)malloc(sizeof(node));
	scanf("%d",&a);
	p->data = a;
	p->next = NULL;
	head = p; 
		
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

	p = head;
	while(p!=NULL)
	{
		printf("\t %d", p->data);
		p = p->next;
	}
	
	printf("\nDeleting the head node.......");

	head = delete_head_node(head);

	printf("\n");
	if(head==NULL)
	{
		printf("The linked is empty");
	}
	else
	{
		p=head;
		while(p!=NULL)
		{
			printf("\t%d",p->data);
			p = p->next;	
		}	
	}

return 0;
}