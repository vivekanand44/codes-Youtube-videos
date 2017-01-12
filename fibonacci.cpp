#include<stdio.h>
#include<conio.h>
void fibonacci(int n)
{
	int a[n];
	int i;	
	a[0] = 0;
	a[1] = 1;
	printf("%d\n",a[1]);
	for(i = 2 ; i <= n ; i++)
	{
		a[i] = a[i-1] + a[i-2];
		printf("%d\n",a[i]);
	}
}

int main()
{	
	int n;
	printf("Enter n");
	scanf("%d",&n);
	fibonacci(n);
	return 0;
}
