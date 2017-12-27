#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node* RemoveDuplicates(node *head)
{
  node *p = head;
  node *q;
  while(p!=NULL && p->next!=NULL)
  {
      if(p->data == p->next->data)
      {
          q = p->next->next;
          
          if(q==NULL)
          {
              p->next = NULL;
              break;         
          } 
          
          p->next = q;
      }
  
      if(p->data != p->next->data)
        p = p->next;
      
  }

    return head;
    
    
}


int main()
{	
	int a , i , n ;
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

start = RemoveDuplicates(start);

while(start!=NULL)
{
	printf("   %d", start->data);
	start = start->next;
}

}
