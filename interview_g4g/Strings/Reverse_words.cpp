#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int start = 0;
	for(int i=0; i<s.length(); i++) {
		if(s[i] == ' ') {
			reverse(s.begin() + start, s.begin() + i);
			start = i+1;
		}	
	}	
	reverse(s.begin() + start, s.end());
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}