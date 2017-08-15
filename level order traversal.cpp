#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct tree
{
	int a;
	struct tree *left;
	struct tree *right;	
}node;

node *queue[100];
int front = -1;
int rear = 0;

void enqueue(node *root)
{	
	queue[rear] = root;
	rear++;		
}

node* dequeue()
{
	front++;
	node *c = queue[front];
	return c;
}

void levelorder(node *root)
{
	node *q;
	printf("\n");
	enqueue(root);
	while(rear-1!=front)
	{
//		printf("\nrear = %d , front = %d",rear , front);
		q = dequeue();		
		printf("%d\t",q->a);
		if(q->left)
			enqueue(q->left);
		if(q->right)
			enqueue(q->right);		
	
	
	}
	
	
	
}


int main()
{
	int n , i;
	node *p , *q , *root;
	printf("Enter the number of nodes");
	scanf("%d",&n);	
	
	for(i=0;i<n;i++)
	{
		if(i == 0)
		{
			p = (node*)malloc(sizeof(node));
			scanf("%d",&p->a);
			p->left = NULL;
			p->right = NULL;
			q = p;
			root = p;
		}
		else
		{	
			p = (node*)malloc(sizeof(node));
			scanf("%d",&p->a);
			p->left = NULL;
			p->right = NULL;
			q = root;
			while(1)
			{				
				if(p->a > q->a)
				{
					if(q->right == NULL)
						{					
						q->right = p;
						break;
						}
					else
						q = q->right;
				}
				else
				{
					if(q->left == NULL)
						{						
						q->left = p;
						break;
						}
					else
						q = q->left;										
				}				
			}
			
		}
		
	}
	

printf("Level order Traversal is :- ");
levelorder(root);	
	
return 0;
}

