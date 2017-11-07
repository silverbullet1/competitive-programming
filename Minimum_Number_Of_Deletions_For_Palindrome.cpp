/***
Simply LCS.cpp with s2 = reverse(s1)
***/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	string s1,s2;
	int m,n;
	
	cout << "Enter the first string : ";
	cin >> s1;
	
	s2 = s1;
	
	reverse(s1.begin(), s1.end());
	
	n = s1.length();
	m = n;

	int dp[n+1][m+1]; //n+1 because 0 is null so 1..n+1 actual string

	for (int i=0; i<=n; i++) //0 upto EQUAL to n..0 is when one string is null
		dp[i][0] = 0;
	
	for (int i=0; i<=m; i++) // ""
		dp[0][i] = 0;
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			if(s1[i] == s2[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
		cout << "Minimum number of deletions required to make the string palindrome = is " << n - dp[n][m] << endl;
	return 0;
}