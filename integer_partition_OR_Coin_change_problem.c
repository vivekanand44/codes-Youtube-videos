#include<stdio.h>
#include<conio.h>

int main()
{
    int n,i,j;
    int a[100][100];

    printf("Enter the number");
    scanf("%d",&n);

    for(i=0;i<=n;i++)
    {
        for (j=0;j<=n;j++)
        {
            a[i][j] = 0;

        }
    }
    
    for (i=1;i<=n;i++)
    {
        a[i][1] = 1;
        a[1][i] = 1; 
        
    }


    for (i=2;i<=n;i++)
    {
        for (j=2;j<=n;j++)
        {
            a[i][j] = a[i-1][j] +  a[i][j-i];

        }
    }

    printf("\n\n The number of ways = %d",a[n][n]);

    printf("\n\n Dynamic Programming Matrix......\n");
    

    printf("\t");
    for (i=0;i<=n;i++)
    {
        printf("%d\t",i);
    }
    for (i=0;i<=n;i++)
    {
        printf("\n");
        printf("%d\t",i);
        for (j=0;j<=n;j++)
        {
            
            printf("%d\t",a[i][j]);
        }
    }

    

getchar();
return 0;

}

