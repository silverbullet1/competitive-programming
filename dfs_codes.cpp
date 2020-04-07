#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >v(1000);
bool visited[1000];

void dfs(int curr) {
	visited[curr] = true;
	for(auto it : v[curr]) {
		if(!visited[it])
			dfs(it);
	}
	return;
}

int main() {
	int n, e, x, y, count = 0;
	cin >> n >> e;
	for(int i = 0; i < e; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);

	for(int i = 0; i < n; i++)
		if(!visited[i]) {
			dfs(i);
			count++;
		}
	if(count == 1) cout <<"Graph is connected.\n";
	else
	cout << "Number of connected components is " << count << endl;
	return 0;
}