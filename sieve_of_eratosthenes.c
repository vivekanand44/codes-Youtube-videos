#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    int limit,q,i , j, n , d , arr[10000];
    printf("Enter the number n : ");
    scanf("%d",&n);

    arr[0] = 1;
    arr[1] = 1; // 1 is not a prime number

    for (i=2;i<=n;i++)
    {
        arr[i] = i;
    }

    
    i = 2;
    d = 2;
    limit = sqrt(n);
    while(d <= limit)
    {
        for(j=d*d;j<=n;j++)
            {
            if ( arr[j]!=1 && (arr[j]%d) == 0)
                {
                    arr[j] = 1;
                }
            }
        
        // find next divisor
                
        d++;
        while(arr[d]==1 && d<=limit)
        {d++;}
             
    }

    printf("\n The prime numbers are =");
    for(i=0;i<=n;i++)
    {
        if(arr[i] !=1) 
        printf("\t%d",arr[i]);
    }


    getchar();
    return 0;
}