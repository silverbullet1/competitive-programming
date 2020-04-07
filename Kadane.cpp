#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int A[n+1];
	for(int i=0; i<n; i++)
		cin >> A[i];
	int current_max = A[0], max_so_far = A[0];
	for(int i=1; i<n; i++) {
		current_max = max(A[i], current_max + A[i]); //Current number bada hai ? (Should I start a new segment from here..?) or should we increase the subarray ?
		max_so_far = max(current_max, max_so_far);
	}
	cout << max_so_far;
}