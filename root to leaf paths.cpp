#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
int data;
struct node *left;
struct node *right;
}node;

int path[20];
int top = -1;

void print_stack()
{
	int i;
	printf("\n");
	printf("Path ==> ");
	for(i=0;i<=top;i++)
	{
		printf("   %d",path[i]);
	}
}

void push(int a)
{
	top++;
	path[top] = a;
}

void pop()
{
	printf("\n %d is popped",path[top]);
	top--;
}


void find_root_to_leaf_paths(node *root)
{
	if(root == NULL)
		return;     
	push(root->data);
	find_root_to_leaf_paths(root->left);
	if(root->left == NULL && root->right == NULL)
		print_stack();		
	find_root_to_leaf_paths(root->right);
	pop();	
	
}

void inorder(node *root)
{    
	if(root)     
		{
		inorder(root->left);
		printf(" %d" , root->data );
		inorder(root->right);
		}
}

int main()
{
    node *p,*q , *root;
    int i, n , k , path[20],flag=0;
	printf("Enter the number of elements");
	scanf("%d",&n);
	p = (node*)malloc(sizeof(node));
	p->left = NULL;
	p->right = NULL;
	printf("Enter the number");
	scanf("%d",&p->data);
	root = p;

	for(i = 1 ;i<n;i++)
	{
	q = (node*)malloc(sizeof(node));
	q->left = NULL;
	q->right = NULL;
	printf("Enter the number");
	scanf("%d",&q->data);

	p = root;
	while(true)
	{
	if (q->data > p->data)
	{
	if(p->right == NULL)
	{
	p->right = q;
	break;
	}
	
	p = p->right;
	}
	else
	{
	if(p->left == NULL)
	{
	p->left = q;
	break;
	}
	
	p = p->left;
	}
	
	}
	
	}    
	inorder(root);
	
	find_root_to_leaf_paths(root);
	
//	printf("\n Tha maximum is %d",getmax(root));
	
	
	
	getch();
	return 0;    
}
