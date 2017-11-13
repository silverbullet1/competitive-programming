#include<bits/stdc++.h>
#define MAX 1005
using namespace std;

bool mark[MAX];
vector<int>primes;

void sieve(int n)
{
	mark[0] = mark[1] = false;
	for(int i=2; i*i <= n; i++) {
		if(!mark[i]){
			for(int j=i*i; j <=n ; j+=i){
				mark[j] = true;
			}
			primes.push_back(i);
		}
	}
}

int main()
{
	memset(mark, 1, sizeof mark);
	primes.clear();
	sieve(MAX);
	for(int i=2; i<MAX; i++)
		if(!mark[i])
			cout << i << " ";
}