#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x,y;
};

struct Node {
	Point p;
	int dist;
};

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int row, col;
bool mat[1000][1000];

int BFS(Point src, Point dest) {

//What if the source or destn itself is blocked ?
	if(!mat[src.x][src.y] || !mat[dest.x][dest.y])
		return INT_MAX;

	bool visited[row][col];
	memset(visited, 0, sizeof visited);

	queue<Node>q;
	Node s = {src, 0};
	q.push(s);

	while(!q.empty()) {
		Node curr = q.front();
		Point currPoint = curr.p;

		//We have reached the destn.
		if(currPoint.x == dest.x and currPoint.y == dest.y) 
			return curr.dist;

		q.pop();

		for(int i=0; i<4; i++) {
			int x = currPoint.x + dx[i];
			int y = currPoint.y + dy[i];
			if(x>=0 && x<row && y>=0 && y<col) {
				visited[x][y] = true;
			Node adj = { {x,y}, curr.dist+1 };
			q.push(adj);
			}
		}
	}
	// iN CASE destination not reached.
	return INT_MAX;
}

int main() {
	cout << "Enter the dimensions of the grid : ";
	cin >> row >> col;
	
	Point src, dest;

	for (int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			cin >> mat[i][j];
	
	//cout << "Enter source and destination :";
	//cin >> src >> dest;
	
	src = {0,0};
	dest = {3,4};
	
	int dist = BFS(src, dest);
	if(dist!=INT_MAX) 
		cout<<"Shortest Path doesn't exist\n";
	else
		cout<<"Shortest path is " << dist << endl;
	
	return 0;

}