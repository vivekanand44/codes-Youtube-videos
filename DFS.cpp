#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;	
};

void DFS(node *root)
{
	if(root)
	{
		printf("  %d",root->data);
		DFS(root->left);
		DFS(root->right);
	}
}


int main()
{
	int n , i;
	struct node *p , *q , *root;
	printf("Enter the number of nodes");
	scanf("%d",&n);	
	
	for(i=0;i<n;i++)
	{
		p = (struct node*)malloc(sizeof(struct node));
		scanf("%d",&p->data);
		p->left = NULL;
		p->right = NULL;
		if(i == 0)
		{
			root = p; // root always point to the root node
		}
		else
		{	
			q = root;   // q is used to traverse the tree
			while(1)
			{				
				if(p->data > q->data)
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


printf("\n DFS:-")
DFS(root);

return 0;
}
