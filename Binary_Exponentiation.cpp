/*
If n is even then x^n can be broken down into (x^2)^(n/2) programatically. And finding x^2 is a one step process.
However, the problem is to find (x^2)^(n/2).

Notice how the computations were reduced from n to n/2 in just one step ? You can continue to divide the power by 2
as long as it is even. 
When n is odd, try to convert it into an even value. x^n can be written as x*x^(n-1). This ensures that n-1 is even.

So, 
If n is even, replace x^n as (x^2)^(n/2).
else x^n = x*x^(n-1) and continue.
*/

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