#include<bits/stdc++.h>
#define MAX 1005
using namespace std;

bool mark[MAX];
void sieve(int n)
{
	for(int i=2; i*i <= n; i++)
		if(!mark[i])
			for(int j=i*i; j <=n ; j+=i)
				mark[j] = true;
}

int main()
{
	memset(mark, 0, sizeof mark);
	sieve(MAX);
	for(int i=2; i<MAX; i++)
		if(!mark[i])
			cout << i << " ";
}