#include<stdio.h>
#include<conio.h>

int main_stack[100] , supporting_stack[100];

int push(int element , int *top , int *stack)
{
	*top = *top + 1;
	stack[*top] = element;
	
}

int pop(int *stack , int *top)
{
	int element;
	if(*top > -1)
	{
	element = stack[*top];
	*top = *top - 1;
	return element;
	}
	else
	{
		printf("\n== STACK EMPTY == \n");
		return -99999;    // means nothing is popped
	}
}



int main()
{
	int choice , element , top_main=-1 , top_support=-1 ,i ,supp_stack_pop_element, popped_element;
	
	printf("Enter the operation : \n 1. Push \n 2.Pop \n 3.check minimum \n 4.STOP \n");
	scanf("%d",&choice);
		
	while(choice != 5)
	{
			
		if (choice == 1)
		{
		
			printf("\nEnter the number to be pushed");
			scanf("%d",&element);
		
			push(element , &top_main , main_stack);		
					
			if (top_support >= 0 && element < supporting_stack[top_support])
			{
				push(element , &top_support , supporting_stack);	
			}
			else if (top_support == -1)
			{
				push(element , &top_support , supporting_stack);
			}
				
			
		}
		else if (choice == 2)
		{
			popped_element = pop(main_stack , &top_main);
			
			if (popped_element != -99999)
				printf("\n Popped element = %d",popped_element);
			
			if (popped_element != -99999)
			{
				if (popped_element == supporting_stack[top_support])
				{
					supp_stack_pop_element = pop(supporting_stack , &top_support);
				}
			}
		}
		else if( choice == 3)
		{
			if (top_support > -1)
				printf("\nMinimum element in the stack = %d \n\n" , supporting_stack[top_support] );
			else
				printf("\n ==== Stack Empty ======");
			
		}
		else if (choice == 4)
		{
						
			if (top_main > -1)
				{
				printf("\n === Main Stack === \n ");
				for (i=top_main;i>=0;i--)
					{
						printf("\n%d",main_stack[i]);
					}
				}	
			else
				printf(" \n ==== STACK EMPTY ===  \n ");
			
			printf("\n top_support = %d", top_support);
			for (i=top_support;i>=0;i--)
				{
					printf("\n%d",supporting_stack[i]);
				}
			
			
		}	
	
	
	printf("\n\nEnter the operation : \n 1. Push \n 2.Pop \n 3.check minimum \n 4.See Full Stack \n 5.STOP \n");
	scanf("%d",&choice);
	
	
	}
	
	
	
	
	
	
	return 0;
}
