/*

Algo :    
Step 1: select a random node A  
Step 2: run bfs/dfs from A and find the farthest node say S  
Step 3: run bfs/dfs from S and find the farthest node say D  
Step 4: d(S, D) is the diameter of the tree

Refer : http://codeforces.com/blog/entry/22276 too
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#define MAX 100001
typedef long long int ll;
using namespace std

bool visited[MAX];
ll dist[MAX]; 

struct node { 
	ll dest;
	ll weight;
};

vector<node> array1[MAX]; 

ll bfs(ll start,ll v) { 
	memset(visited,false,sizeof(visited));
	memset(dist,0,sizeof(dist));
	queue<ll> q;
	q.push(start);
	visited[start]=true;
	dist[start]=0;
	while(!q.empty())	{
		 ll s=q.front();
		 q.pop();
		for(ll j=0;j<array1[s].size();j++)	{ 
			if(!visited[array1[s][j].dest]) { 
				visited[array1[s][j].dest]=true;
				q.push(array1[s][j].dest);
				dist[array1[s][j].dest]=array1[s][j].weight+dist[s]; 
				} 
			} 
		}
	return max_element(dist+1,dist+v+1)-dist;
}

int main(){ 
	ll t;
	cin>>t;
	while(t--)	{ 
	ll v;
	cin>>v; 
	for(int i=1;i<=v;i++) 
		array1[i].clear(); // this is an array that is compoed of vector units that compries of nodes.
	for(ll i=1;i<v;i++)	 {// array[i] -> is a vector of nodes corresponding to ith node
		ll a,b,w; // each node has to be pushed back onto the vector(i) 
		cin>>a>>b>>w;
		node temp;
		temp.dest=b;
		temp.weight=w;
		array1[a].push_back(temp);
		temp.dest=a;
		array1[b].push_back(temp); 
	}
/*for(int i=1;i<=v;i++)
{ for(int j=0;j<array[i].size();j++)
{ cout<<i<<" "<<array[i][j].dest<<" "<<array[i][j].weight<<endl;
}

}*/ 
	ll index=bfs(1,v);
	ll index2=bfs(index,v);
	ll ans=dist[index2];

	cout<<ans<<endl;
	}	
}