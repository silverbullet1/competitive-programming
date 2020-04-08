#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s1, s2;
        map<char,int>mp1, mp2;
        mp1.clear(); mp2.clear();
        cin >> s1 >> s2;
        for(int i=0; i<s1.length(); i++)
            mp1[s1[i]]++;
            
        for(int i=0; i<s2.length(); i++)
            mp2[s2[i]]++;
        
        int flag = 0;
        
        for(auto it : mp1) {
            if(it.second!=mp2[it.first]) {
                flag = -1; // Could not find this character in the other map
                break;
            }
        }
        
        for(auto it : mp2) {
            if(it.second!=mp1[it.first]) {
                flag = -1; 
                break;
            }
        }
        (flag==-1)?printf("NO\n"):printf("YES\n");
    }
	return 0;
}