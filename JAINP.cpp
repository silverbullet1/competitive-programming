// Amazing takes time, legendary requires patience
#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9+7;
const int eps = -1e6;
const int MAX = 100010;
#define sd(n) scanf("%d", &(n))
#define rep(i, x, n) for (int i = x, _n = (n); i < _n; ++i)
#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
#define SZ(c) (int)(c).size()
#define pra(v, n) rep(i, 0, n) cout << v[i] << " "; cout << endl;
#define lcm(a,b) (a*(b/__gcd(a,b)))
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define mii map<int, int>
#define pii pair<int, int>
#define pip pair<int, pii>
#define F first
#define S second
#define ll long long int
#define llu unsigned long long
#define CLR(p) memset(p, 0, sizeof(p))
#define SET(p) memset(p, -1, sizeof(p))
#define INF 0x3f3f3f3f
#define pi 3.14159265358979
#define debug 0
#define vi vector<int>
#define vvi vector< vi >
#define pb push_back
#define rall(c) c.rbegin(),c.rend() 
#define sz(c) c.size()
#define tr(c,it)  for(typeof(c.begin()) it=c.begin();it!=c.end();it++)  
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define present(c,x) find(all(c),x)!=c.end()
#define cpresent(c,x) c.find(x)!=c.end()  
#define permute(c) next_permutation(all(c))
#define MAX 100005
#define N 311111


static struct IO {
	char tmp[1 << 10];
 
	// fast input routines
	char cur;
 
//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
	inline char nextChar() { return cur = getc_unlocked(stdin); }
	inline char peekChar() { return cur; }
 
	inline operator bool() { return peekChar(); }
	inline static bool isBlank(char c) { return (c < '-' && c); }
	inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }
 
	inline IO& operator >> (char & c) { c = nextChar(); return *this; }
 
	inline IO& operator >> (char * buf) {
		if (skipBlanks()) {
			if (peekChar()) {
				*(buf++) = peekChar();
				while (!isBlank(nextChar())) *(buf++) = peekChar();
			} *(buf++) = 0; } return *this; }
 
	inline IO& operator >> (string & s) {
		if (skipBlanks()) {	s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar(); }
		return *this; }
 
	inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}
 
#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}
 
defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)
 
	// fast output routines
 
//#define putChar(c) putc_unlocked((c), stdout)
	inline void putChar(char c) { putc_unlocked(c, stdout); }
	inline IO& operator << (char c) { putChar(c); return *this; }
	inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }
 
	inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }
 
	char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
	inline IO& operator << (double d) { return (*this) << toString(d); }
 
 
#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }
 
defineOutFor(int)
defineOutFor(long long)
 
#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;

int mp[MAX][10];
map<set<int>,int> has;
set<int>curr_set;
map<char,int> vals;

void generateSubsets(char *set, int set_size, int num_strings) 
{
    int pow_set_size = pow(2, set_size); 
    int cnt, j;
	has.clear();
	int v[num_strings];
	
    for(cnt = 0; cnt < pow_set_size; cnt++) 
    {	
    	curr_set.clear();
    	CLR(v);
	    int ans = 0;
	    for(j = 0; j < set_size; j++) 
	    { 
	    	int current_subset_bit = cnt & (1 << j);
	        if(current_subset_bit) {
	        	curr_set.insert(j);
			    for(int k = 0; k < num_strings; k++) {
		    		if(mp[k][vals[set[j]]])
		    			v[k]++;
			    }
	        }
	    }
        for(int k = 0; k < num_strings; k++) {
        	if(curr_set.size() > 0 && v[k] == curr_set.size()) {//Should have all the characters in the current subset
        		ans++;
        	}
        }
		has[curr_set] = ans;
	}
} 


int main() {
	int T;
	vals['a']=0;
	vals['e']=1;
	vals['i']=2;
	vals['o']=3;
	vals['u']=4;
	cin >> T;
	while(T--) {
		int n;
		string str;
		cin >> n;
		for(int i=0; i<n; i++) {
			CLR(mp[i]);
			cin >> str;
			for(int j=0; j<str.length(); j++) {
				if(str[j] == 'a') mp[i][0]=1;
				if(str[j] == 'e') mp[i][1]=1;
				if(str[j] == 'i') mp[i][2]=1;
				if(str[j] == 'o') mp[i][3]=1;
				if(str[j] == 'u') mp[i][4]=1;
				if(mp[i][0] + mp[i][1] +  mp[i][2] +mp[i][3] + mp[i][4] == 5)
					break;
			}
		}
		generateSubsets("aeiou", 5, n);
		set<int>missing;
		long long ans = 0;
		
		for(int i=0; i<n; i++) {
			missing.clear();
			if(mp[i][0]!=1) missing.insert(0);
			if(mp[i][1]!=1) missing.insert(1);
			if(mp[i][2]!=1) missing.insert(2);
			if(mp[i][3]!=1) missing.insert(3);
			if(mp[i][4]!=1) missing.insert(4);
			if(missing.size() > 0)
				ans = ans + has[missing];
			else
				ans = ans + (n - 1); //I can pare up with anybody in the fucking world..except myself
		}
		cout << ans/2 << endl; //unordered pairs
	}
	return 0;
}