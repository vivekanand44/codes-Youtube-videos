#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node *reverse(node *head)   //reverse the string (second part)
{
node *p , *q;
if(head == NULL)
return head;
p = head;
q = p->next;
if(q == NULL)
return p;
q = reverse(q);
p->next->next = p;
p->next = NULL;
return q;
}

int main()
{
int a , i , n;
node *p,*q,*start , *new_start;
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
	
printf("reversed Linked list is => \n");	
new_start = reverse(start);
while(new_start!=NULL)
{
	printf("   %d",new_start->data);
	new_start = new_start->next;
}
	
	
return 0;
}
