#include <bits/stdc++.h>
using namespace std;


int main() {
	for(int n=1; n<=9; n++) {
	int A[n+1];
	map<string,int>mp;
	mp.clear();
	for(int i=1;i<=n;i++)
		A[i-1] = i;
	for(int k=1; k<10000000; k++) {
		int B[n+1];
		for(int r=0; r<n; r++)
			B[r] = A[r];
			
		for(int i=0;i<n;i++) {
			int j = rand()%n;
			swap(B[i],B[j]);
			
		}
		string str = "";
		for(int i=0;i<n;i++) {
			str+=to_string(B[i]);
		}
		mp[str]++;
		//cout<<str<<endl;
	}
	string keymin, keymax;
	int max = INT_MIN, min = INT_MAX;
	for(auto it : mp) {
		if(it.second>max) {
			max = it.second;
			keymax = it.first;
		}
		if(it.second<min) {
			min = it.second;
			keymin = it.first;
		}
		//if(n==7)
		//cout << it.first <<" " <<it.second << endl;
	}
		cout <<keymax<<" "<<max<<endl;
		cout <<keymin<<" "<<min<<endl;	
	}
	return 0;
}