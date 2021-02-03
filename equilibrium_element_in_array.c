#include<stdio.h>


int main()
{
	int a[] = {-7, 1, 5, 2, -4, 3, 0};
	int n,i;
	int leftSum = 0;
	int rightSum = 0;
	int sum = 0;
	
	n = sizeof(a) / sizeof(a[0]);
		
	for(i=0;i<n;i++)
	{
		sum = sum + a[i];	    // total sum
	}
	
	rightSum = sum;
	
	for(i=0;i<n;i++)
	{
		rightSum = rightSum - a[i];
		
		if(leftSum == rightSum)
			{			
			printf("Index of eq element is %d , element= %d",i,a[i]);
			break;
			}
		leftSum = leftSum + a[i]; 
	}
	
	
	return 0;
}
