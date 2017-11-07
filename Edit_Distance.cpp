/***

Case 1: Last char­ac­ters are same , ignore the last character.
Recur­sively solve for m-1, n-

Case 2: Last char­ac­ters are not same then try all the pos­si­ble oper­a­tions recursively.
Insert a char­ac­ter into s1 (same as last char­ac­ter in string s2 so that last char­ac­ter in both the strings are same): now s1 length will be m+1, 
s2 length : n, ignore the last char­ac­ter and Recur­sively solve for m, n-1.

Remove the last char­ac­ter from string s1. now s1 length will be m-1, s2 length : n, Recur­sively solve for m-1, n

Replace last char­ac­ter into s1 (same as last char­ac­ter in string s2 so that last char­ac­ter in both the strings are same): s1 length will be m, s2 length : n, ignore the last char­ac­ter and Recur­sively solve for m-1, n-1.
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


    //base case
    //If any of the string if empty then number of operations
    //needed would be equal to the length of other string
    //(Either all characters will be removed or inserted)

	for (int i=0; i<=n; i++) 
		dp[i][0] = i;
	
	for (int i=0; i<=m; i++) // ""
		dp[0][i] = i;
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1 + min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]); //1 is the unit cost for all 3 operations, if chars mismatch we add 1 to the total cost.
		}
		cout << "Edit distance = " << dp[n][m] << endl;
	return 0;
}