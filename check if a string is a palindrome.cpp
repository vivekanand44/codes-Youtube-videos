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

void check_palindrome(node *start)
{
	node *p , *q ,*first_start,*second_start;
	p = start;
	q = start;
	
	if(p->next == NULL)          // if there is only one character in the string
	{
		printf("It is a palindrome");
		return;
	}
	//split the linked list
	while(1)
	{
		p = p->next->next;
		if(p == NULL)
		{
			second_start = q->next;
			break;
		}
		if(p->next == NULL)
		{
			second_start = q->next->next;
			break;
		}		
		q = q->next;		
	}	
	q->next = NULL;
	//reverse the second linked list
	second_start = reverse(second_start);	
//	printf(" \n second start  =  %d",second_start->data);	
	//now compare the splitted two linked lists
	first_start = start;
		
	while(first_start!=NULL && second_start!=NULL) //compare the two strings
	{		
		if(first_start->data == second_start->data)
		{
			first_start = first_start->next;
			second_start = second_start->next;
		}
		else
		{
			printf("\n Not a Palindrome");
			return;					
		}		
	}	
	printf("It is a palindrome");
}


int main()
{	
	int a , i , n , cnt , r;
	node *p,*q,*start , *temp , *new_start;
	printf("Enter the number of nodes");
	scanf("%d",&n);
	
	if(n == 0)   //an empty string
	{
		printf("It is a Palindrome");
		return 0;
	}
	
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

	check_palindrome(start);
		
return 0;
}
