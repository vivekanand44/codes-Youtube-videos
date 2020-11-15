#include<stdio.h>
#include<conio.h>

int main()
{
    int a,b,n,i,j,choice, coin , amount;
    int arr[100][100];

    printf("Enter the operation number to be performed :- \n 1. Integer Partition \n 2. Coin Change Problem\n");
    scanf("%d",&choice);
    
    if (choice == 1)
    {
        printf("\nEnter the Integer :- ");
        scanf("%d",&n);
        a = n;
        b = n;
    }
    else if(choice == 2) 
    {
        printf("\nEnter the highest coin value...");
        scanf("%d",&coin);
        printf("\nEnter the total amount...");
        scanf("%d",&amount);
        a = coin;
        b = amount;    
    
    }
    


    
    for(i=0;i<=a;i++)
    {
        for (j=0;j<=b;j++)
        {
            arr[i][j] = 0;

        }
    }
    
    for (i=1;i<=a;i++)
    {
        arr[i][1] = 1;
    }
    for (j=1;j<=b;j++)
    {
        arr[1][j] = 1;
    }

    for (i=2;i<=a;i++)
    {
        for (j=2;j<=b;j++)
        {
            arr[i][j] = arr[i-1][j] +  arr[i][j-i];
        }
    }

    printf("\n\n The number of ways = %d",arr[a][b]);

    printf("\n\n Dynamic Programming Matrix......\n");
    

    printf("\t");
    for (j=0;j<=b;j++)
    {
        printf("%d\t",j);
    }
    for (i=0;i<=a;i++)
    {
        printf("\n");
        printf("%d\t",i);
        for (j=0;j<=b;j++)
        {
            
            printf("%d\t",arr[i][j]);
        }
    }

    

getchar();
return 0;

}

