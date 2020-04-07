#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, L = 0, R, ans = 0;
		string s;
		bool matched = false;
		char x;
		cin >> n;
		cin >> s >> x;
		for(int i = 1; i <= n; i++) {
			matched = false;
			if(s[i-1] == x) {
				if(L == 0) {
					R = i;
					ans = ans + (R*(R+1)/2 - L*(L+1)/2) - ((R-1)*R/2 - (L-1)*L/2);
					cout << L << " " << R << " " <<ans << endl;
					L = R;
					R = -1;
				}
				
				else if(R == -1) {
					R = i;
					ans = ans + (R*(R+1)/2 - (L+1)*(L+2)/2);
					cout << L << " " << R << " " <<ans<< endl;
					L = R;
					R = -1;
					matched = true;
				}
			}
		}
		if(!matched) { //When there's no matching R of last L
				R = n;
				ans = ans + (R*(R+1)/2 - (L+1)*(L+2)/2);
		}
		cout << ans << endl;
	}
	return 0;
}