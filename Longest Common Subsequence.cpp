#include<iostream>
#include<string>
using namespace std;

int main()
{	
	string str1 = "abcdefgh";
	string str2 = "pqbrcueg";
	
	int m , n;
	char lcs[10];
	m = str1.length();
	n = str2.length();
	
	int a[m+1][n+1];
	
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			a[i][j] = 0;		
		}
	}
	int k = 0;
	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(str1[i] == str2[j])
			{
				a[i][j] = a[i-1][j-1] + 1;
				lcs[k] = str1[i];
				k++;				
			}		
			else
			{
				if(a[i-1][j] > a[i][j-1])
					{
						a[i][j] = a[i-1][j];
					}
				else
					{
						a[i][j] = a[i][j-1];	
					}
			}
		}
	}
	lcs[k] = '\0';
	cout << lcs;

return 0;
}

