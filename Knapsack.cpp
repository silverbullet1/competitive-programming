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

	for (int i=0; i<=n; i++)
		for (int j=0; j<=W; j++) {
			if(i==0 or j==0)
				dp[i][j] = 0; //If bag has no space or no items in the house to begin with.
			if(w[i-1] <= j) // If we had a weight of j
				dp[i][j] = max(dp[i-1][j], cost[i-1] + dp[i-1][j-w[i-1]]);
			else
				dp[i][j] = dp[i-1][j]; 
		}
		cout << "Largest values possible = " << dp[n][W] << endl;
	return 0;
}