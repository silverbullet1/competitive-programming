#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char,int> mp;
    mp.clear();
    mp['I'] = 1;
    // mp['IV'] = 4; //These values are derivable so no need to store!!
    mp['V'] = 5;
    // mp['IX'] = 9;
    mp['X'] = 10;
    // mp['XL'] = 40;
    mp['L'] = 50;
    // mp['XC'] = 90;
    mp['C'] = 100;
    // mp['CD'] = 400;
    mp['D'] = 500;
    // mp['CM'] = 900;
    mp['M'] = 1000;
    
    int T;
    cin >> T;
    string str;
    while(T--) {
        cin >> str;
        int ans = 0;
        for(int i=0; i<str.length(); i++) {
            // Say string is IXXI..how will you solve it ? IX is 1+10..because I<X so we need to check that! XI is X+I
            if(i+1<str.length()) { //Case when we can pick 2 characters together
                char s1 = str[i]; //Current char
                char s2 = str[i+1]; //Next char
                if(mp[s1] >= mp[s2]) // Case : XI means treat X and I separately
                    ans = ans + mp[s1]; //Just add the value of X
                else { // Case : IX means treat this as X-I because I<X 
                    ans = ans + (mp[s2] - mp[s1]);
                    i++; //We have processed 2 characters(IX) so increment i twice
                }
            }
            else ans = ans + mp[str[i]];
        }
            cout << ans << endl;
    }
	return 0;
}