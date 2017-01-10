#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

void reverse(node *head)
{

if(head == NULL)
	return;


if(head -> next == NULL)
	return;


reverse(head->next);

head->next->next = head;
head->next = NULL;

}

node *swap_in_a_group(node *start , int k)
{
	//swap the linked list in group size = k
	node *p , *q ,*new_start , *temp;
	int cnt;
	p = start;
	cnt = 0;
	while(cnt != k-1)    // go to the 'K'th node
	{
		if(p->next == NULL)
			{
			return start;
			}
		p = p->next;
		cnt++;
	}
	
	new_start = p; //the new start		
	q = new_start;	
	while(1)
	{
		p = start;
		temp = q->next;
		if(temp == NULL)  // if total number of nodes is divisible by K (multiple of K)
		{
			reverse(p);
			return new_start;
		}
		
		q->next = NULL;
		q = temp;
		start = temp;
		
		cnt = 0;
		//in the last outside while loop , if remainder is non-zero number of nodes
		while(cnt != k-1) 
		{
			if(temp->next == NULL)
				{
					reverse(p);	
					p->next = q;
					return new_start;
				}		
			temp = temp->next;
			cnt++;
		}
		
		reverse(p);
		p->next = temp;
		q = temp;
	}

return new_start;
}

int main()
{
	int a , i , n , cnt , k=4 , flag = 1;
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
	
	printf("\n Enter K  ");
	scanf("%d",&k);
	
	printf("\n swapped list==");
	p = swap_in_a_group(start , k);  //call the function
	while(p!=NULL)
	{
		printf("%d  ",p->data);
		p = p->next;
	}


	
return 0;	
}
