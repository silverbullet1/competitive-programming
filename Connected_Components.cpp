#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

bool visited[MAX];
vector<vector<int> >v;

void dfs(int num) {
	visited[num] = true;
	for (auto it : v[num])
		if(!visited[it])
			dfs(it);
}
	
int main() {
	int V, E, x, y, count = 0;
	
	cout << "Enter the no. of vertices and edges : ";
	cin >> V >> E;

	v.resize(V+1);	v.clear();

	memset(visited,0,sizeof visited);

	cout << "Enter the edges :\n";
	for(int i = 0; i < E; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x); //Considering undirected graph ATM
	}

	for(int i = 0; i < V; i++) {
		if(!visited[i]) {
			dfs(i);
			count ++;
		}
	}
	cout << "Number of connected components are : " << count << endl;
	
}