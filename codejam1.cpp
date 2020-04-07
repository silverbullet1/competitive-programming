#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int k = 1; k <= T; k++) {
		int n, p;
		cin >> n >> p;
		string prefix;
		map<long long, long long>mp;
		mp.clear();
		for(int i = 0; i < p; i++) {
			cin >> prefix;
			long long res = 1;
			for(int j = prefix.length(); j < n; j++)
				res = res*2;
			mp[2] += res;
		}
		long long ans = pow(2, n) - mp[2];
		if(ans == -1) ans = 0;
		cout << "Case #" << k << ": " << abs(ans) << endl;
	}
}