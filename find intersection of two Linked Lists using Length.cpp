#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node *newNode(int data)
{
	node *p;
	p = (node*)malloc(sizeof(node)); 
	p->data = data;   // First node
	p->next = NULL;
	
	return p;  
}
int find_length(node *start)
{
	int cnt = 0;
	node *p;
	p = start;
	while(p!=NULL)
	{
		cnt++;
		p = p->next;
	}

return cnt;
}
node *find_intersection(node *p , node *q)
{
	node *larger , *smaller;
	int m , n , d , cnt;
	m = find_length(p);   //calculate length
	n = find_length(q);
	
	d = m-n;  //find difference
	if(d < 0)  //find absolute value
	{
		d = d * -1;
	}
	
	if(m > n) //   find larger length linked list
		{
			larger = p;
			smaller = q;
		}
	else
		{
			larger = q;
			smaller = p;
		}
		
	cnt = 0;
	while(cnt < d)    // move d nodes in larger linked list
	{
		larger = larger->next;
		cnt++;
	}
	
	while(larger != smaller)   // then move one step each in both linked lists
	{
		larger = larger->next;
		smaller= smaller->next;
	}
	
	return larger;   // this is the intersection
	
}


int main()
{
	node *p , *q , *intersection;
	p = newNode(1);
	p->next = newNode(2);
	p->next->next = newNode(3);
	p->next->next->next = newNode(4);
	intersection = p->next->next->next;
	p->next->next->next->next = newNode(5);
	p->next->next->next->next->next = newNode(6);
	
	q = newNode(7);
	q->next = newNode(8);
	q->next->next = intersection;
	
	printf("\n The intersection point is %d",find_intersection(p , q)->data);
return 0;
}
