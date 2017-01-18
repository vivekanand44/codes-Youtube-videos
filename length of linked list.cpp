#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

int find_length(node *start)
{
	int cnt = 0;
	node *p;
	p = start;
	while(p!=NULL)
	{
		cnt++;         //cnt calculates the length
		p = p->next;
	}

return cnt;
}

int main()
{	
	int a , i , n , l ;
	node *p,*q,*start;
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

l = find_length(start);
printf("The length is %d",l);
}
