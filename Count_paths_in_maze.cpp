#include<bits/stdc++.h>
#define N 105
using namespace std;

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
int n;
long long ans;

bool isSafe(int x, int y)
{
    if(x>=0 and x<n and y>=0 and y<n)
        return true;
    else
        return false;
}

void count_path(bool mat[N][N], int x, int y, bool visited[N][N])
{
    if(x == n-1 and y == n-1) {
        ans++;
        return;
    }
    
    visited[x][y] = true;   
    
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(mat[nx][ny] == 0 and isSafe(nx,ny) && !visited[nx][ny])
             count_path(mat, nx, ny, visited);
    }
    
    visited[x][y] = 0;
    
    return;
}

int main() 
{
    bool mat[N][N], vis[N][N];
    memset(vis, 0, sizeof vis);
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
                cin>>mat[i][j];
    count_path(mat, 0, 0, vis);
    cout << ans << endl;
    return 0;
}
