#include <iostream>
using namespace std;

string expandFromMiddle(string str, int begin, int end) {
    int n = str.length();
    while(begin >= 0 && end < n   && str[begin] == str[end]) {
        begin--;
        end++;
	}
    string s = str.substr(begin+1, end-(begin+1));
    return s;
}

int main() {
    int T;
    cin >> T;
    string str;
    while(T--) {
        cin >> str;
        int len = 0;
        string s = str.substr(0,1);
        for(int i=0; i<str.length(); i++) {
            string s1 = expandFromMiddle(str, i, i);
            string s2 = expandFromMiddle(str, i, i+1);
            int len1 = s1.length();
            int len2 = s2.length();
            if(len1 > len) {
                s = s1;
                len = len1;
            }
            if(len2 > len) {
                s = s2;
                len = len2;
            }
        }
        cout << s << endl;
    }
	return 0;
}