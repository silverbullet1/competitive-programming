#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s1, s2;
        cin >> s1 >> s2;
        int flag = 0;
        int cnt1[256];
        int cnt2[256];
        memset(cnt1, 0, sizeof cnt1);
        memset(cnt2, 0, sizeof cnt2);
            
        for(int i = 0; i < s1.length(); i++)
            cnt1[s1[i] - '0']++;
        
        for(int i = 0; i <s2.length(); i++)
            cnt2[s2[i] - '0']++;

        for(int i=0; i<256; i++)
            if(cnt1[i] != cnt2[i]) {
                    flag = -1;
                    break;
            }
        (flag==-1)?printf("NO\n"):printf("YES\n");
    }
    return 0;
}