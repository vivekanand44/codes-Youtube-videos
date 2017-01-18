#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
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

int main()
{
	int len_loop;
	node *p , *q , *loop_node , *one_step , *two_steps , *length_calculator;
	p = newNode(1);
	p->next = newNode(2);
	p->next->next = newNode(3);
	p->next->next->next = newNode(4);
	loop_node = p->next->next->next;
	p->next->next->next->next = newNode(5);
	p->next->next->next->next->next = newNode(6);
	p->next->next->next->next->next->next = newNode(7);
	p->next->next->next->next->next->next->next = newNode(8);
	p->next->next->next->next->next->next->next->next = loop_node;	
	//detect loop code
	one_step = p;
	two_steps = p;
	while(1)
	{
		if(one_step == NULL || two_steps == NULL)
		{
			printf("\n There is no loop");
			break;
		}		
		one_step = one_step->next;
		two_steps = two_steps->next->next;
		if(one_step == two_steps)
		{
			printf("\n There is a loop");
			break;
		}		
	}
	//find the length of the loop
	len_loop = 1;
	length_calculator = one_step->next;
	while(length_calculator!=one_step)
	{
		len_loop = len_loop+1;
		length_calculator = length_calculator->next;		
	}
	printf("\n\n Length of the loop is %d",len_loop);	
	//find the starting point of the loop
	// p is at the starting of the linked list	
	q = one_step;
	while(p!=q)
	{
		p = p->next;
		q = q->next;
	}	
	printf("\n The starting point of the loop is  %d", p->data);
return 0;	
}
