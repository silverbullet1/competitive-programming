#include <bits/stdc++.h>
using namespace std;

int LCS(string str1, string str2) {
    
    int n = str1.length();
    int m = str2.length();
    
    int LCS[n+1][m+1];
    memset(LCS, 0, sizeof LCS);
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++) {
            if(i==0 || j==0)
                LCS[i][j] = 0;
            else if(str1[i-1] == str2[j-1])
        	    LCS[i][j] = LCS[i-1][j-1] + 1;
            else
        	    LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
    return LCS[n][m];

}

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        string s1 = s;
        reverse(s.begin(), s.end());
        cout << s.length() - LCS(s, s1) << endl;
    }
	return 0;
}