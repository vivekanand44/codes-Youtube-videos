#include<iostream>
#include<string>
using namespace std;

int main()
{	
	string str1 = "abcvdefgh";
	string str2 = "bqdrcvefgh";
	int m , n;
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
			if(str1[i-1] == str2[j-1])
			{
				a[i][j] = a[i-1][j-1] + 1;				
							
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
	cout <<"Length of Longest Common Subsequence is" << a[m][n];
	//Now let us find out the Longest common subsequence //
	int i = m;
	int j = n;
	char lcs[a[m][n]];
	k = a[m][n]-1;
	lcs[k] = '\0';
	while(i > -1 && j > -1)
	{
		if(str1[i-1] == str2[j-1])
		{	
			lcs[k] = str1[i-1];
			i--;
			j--;
			k--;
		}
		else
		{
			if(a[i-1][j] > a[i][j-1])
				{
					i = i-1;
				}
			else
				{
					j = j-1;
				}
		}
	}
	cout <<"\n\n The Longest Common Subsequence is=> " << lcs;
return 0;
}

