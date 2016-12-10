#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str = "abcecqba";
	int n = str.length();
	int a[n][n];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	}
	
	int l = 1;
	while(l <= n-1)
	{
		int i = 0;
		while(i+l <=n-1)
		{
			int j = i+l;
			if(str[i] == str[j])
				a[i][j] = a[i+1][j-1] + 2;
			else
			{
				if(a[i+1][j] > a[i][j-1])
					a[i][j] = a[i+1][j];
				else
					 a[i][j] = a[i][j-1];
			}
			
			i = i + 1;
		}
		
		l = l + 1;
	}
	
//	cout << a[0][n-1];
	
	int palindrome_length = a[0][n-1];
	char palindrome[palindrome_length];
	palindrome[palindrome_length] = '\0';
	int i = 0;
	int j = n-1;
	int palindrome_start = 0;
	int palindrome_end = palindrome_length-1;
	
	while(palindrome_end - palindrome_start >=1)
	{
			if(str[i] == str[j])
			{
				palindrome[palindrome_start] = str[i];
				palindrome[palindrome_end] = str[i];
				palindrome_start = palindrome_start + 1;
				palindrome_end = palindrome_end - 1;
				i = i+1;
				j = j-1;
			}
			else
			{
				if(a[i+1][j] > a[i][j-1])
				{					
					i = i+1;
				}
				else
				{
					j = j-1;				
				}
			}		

	}
	if(palindrome_end == palindrome_start)
		palindrome[palindrome_end] = str[i];
	cout <<"\n Lenght of the LPS is =>" << palindrome_length;
	cout <<"\n The LPS is =>" << palindrome;
return 0;	
}
