#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while(T--) {
        string str;
        getline(cin, str);
        int cnt[256] = {0}; 
        for(int i=0; i<str.length(); i++)
            if(cnt[str[i]] == 0) {
                cout << str[i];
                cnt[str[i]]++;
            }
        cout << endl;
    }
	return 0;
}