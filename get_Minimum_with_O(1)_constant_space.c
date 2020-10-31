#include<stdio.h>
#include<conio.h>


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
	int stack[100];
	int choice , x , top=-1  ,i , y , me , ce ;

	printf("Enter the operation : \n 1. Push \n 2.Pop \n 3.check minimum \n 4.STOP \n");
	scanf("%d",&choice);

	while(choice != 5)
	{

		if (choice == 1)
		{

			printf("\nEnter the number to be pushed");
			scanf("%d",&x);

			if (top > -1)
			{
				if ( x < me)
				{
				  ce = 2 * x - me;
				  push(ce , &top , stack);
				  me = x;
				}
				else
				{
					push(x , &top , stack);
				}
			}
			else
			{
				ce = x;
				push(ce , &top , stack);
				me = x;
			}


		}
		else if (choice == 2)
		{
			if (top > -1)
				{
				y = pop(stack , &top);

					if (y != -99999)
					{
						printf("\n Top Element popped");
						if( y < me )
						{
							me = 2 * me - y;
						}
					}

				}
		}
		else if( choice == 3)
		{
			if (top > -1)
				printf("\nMinimum element in the stack = %d \n\n" , me );
			else
				printf("\n ==== Stack Empty ======");

		}
		else if (choice == 4)
		{

			if (top > -1)
				{
				printf("\n === Main Stack === \n ");
				for (i=top;i>=0;i--)
					{
						printf("\n%d",stack[i]);
					}
				}
			else
				printf(" \n ==== STACK EMPTY ===  \n ");


		}


	printf("\n\nEnter the operation : \n 1. Push \n 2.Pop \n 3.check minimum \n 4.See Full Stack \n 5.STOP \n");
	scanf("%d",&choice);


	}

return 0;
}
