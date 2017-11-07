/***

***/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n, W;

	cout << "Enter the number of items and capacity of the bag: ";
	cin >> n >> W;

	int cost[n+1], w[n+1];

	cout << "Enter the weights : ";
	for(int i=0; i<n; i++) 
		cin>>w[i];

	cout << "Enter the costs : ";
	for(int i=0; i<n; i++) 
		cin>>cost[i];	

	// Summation w_i <=W 
	// Some of costs = Maximum

	int dp[n+1][W+1]; // dp[i][j] Stores the maximum value that can be accomodated with using first i weights in a  knapsack of weight  j.

	for (int i=0; i<=n; i++) // If no items in the house
		dp[i][0] = 0;
	
	for (int i=0; i<=W; i++) // If the bag is empty then 
		dp[0][i] = 0;
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=W; j++) {
			if(w[i] <= W)
				dp[i][j] = max(dp[i-1][j], cost[i-1] + dp[i-1][j-w[i-1]]); //(add 1 to the result and remove the last character from both the strings and check the result for the smaller string.)
			else
				dp[i][j] = dp[i-1][j]; //Since its substring and not subsequence, this killing spree ends here.
		}
		cout << "Largest values possible = " << dp[n][W] << endl;
	return 0;
}