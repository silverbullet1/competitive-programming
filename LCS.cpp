/***
Recursion:

Start comparing strings in reverse order one character at a time.

Now we have 2 cases -

Both characters are same
add 1 to the result and remove the last char­ac­ter from both the strings and make recursive call to the modified strings.
Both characters are different
Remove the last char­ac­ter of String 1 and make a recur­sive call and remove the last char­ac­ter from String 2 and make a recursive 
and then return the max from returns of both recursive calls. see example below
Example:
=======

Case 1: 
-------

String A: "ABCD", String B: "AEBD"

LCS("ABCD", "AEBD") = 1 + LCS("ABC", "AEB")

Case 2: 
-------

String A: "ABCDE", String B: "AEBDF"

LCS("ABCDE", "AEBDF") = Max(LCS("ABCDE", "AEBD"), LCS("ABCD", "AEBDF"))
***/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	string s1,s2;
	
	cout << "Enter the first string : ";
	cin >> s1;

	cout << "Enter the second string : ";
	cin >> s2;
	
	int n = s1.length();
	int m = s2.length();

	int dp[n+1][m+1]; //n+1 because 0 is null so 1..n+1 actual string

	for (int i=0; i<=n; i++) //0 upto EQUAL to n..0 is when one string is null
		dp[i][0] = 0;
	
	for (int i=0; i<=m; i++) // ""
		dp[0][i] = 0;
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
		cout << "The Longest Common Subsequence is " << dp[n][m] << endl;
	return 0;
}