#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll a, ll b, ll mod = 1e9 + 7) {

	ll res = 1;
	a = a%p;
	while(b>0) {
		if(b&1)
			res = (res*a)%mod;
		
		b = (b>>1);
		a = (a*a)%mod;
	}
	return res;
}

int main()
{
   int x = 2;
   int y = 5;
   int p = 13;
   printf("Power is %u", power(x, y));
   return 0;
}