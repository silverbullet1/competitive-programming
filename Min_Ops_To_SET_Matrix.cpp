/*
Given a binary matrix of N rows and M columns. The operation allowed on the matrix is 
to choose any index (x, y) and toggle all the elements between the rectangle having 
top-left as (0, 0) and bottom-right as (x-1, y-1). Toggling the element means changing 
1 to 0 and 0 to 1. The task is to find minimum operations required to make set all the 
elements of the matrix i.e make all elements as 1.
*/

/*The key idea is to start from the end point (N – 1, M – 1) and traverse the matrix in
reverse order. Whenever we encounter a cell which has a value of 0, flip it.
Suppose there are 0s at both (x, y) and (x + 1, y + 1) cell. You shouldn’t flip a cell 
(x + 1, y + 1) after cell (x, y) because after you flipped (x, y) to 1 [(1,1) se leke 
(x,y), in next move to flip (x + 1, y + 1) cell, you will flip again (x, y) to 0. So there is no 
benefit from the first move for flipping (x, y) cell.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, n, m;
    cin >> T;
    while(T--) {
        int ans = 0;
        cin >> n >> m;
        
        char str[50][50];
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin >> str[i][j];
                
        for(int i=n-1; i>=0; i--)
            for(int j=m-1; j>=0; j--)
                if(str[i][j] == '0') {
                    ans++;
                        for(int h=0; h<=i; h++)
                            for(int k=0; k<=j; k++)
                                if(str[h][k] == '0')
                                    str[h][k]='1';
                                else
                                    str[h][k]='0';
                        
    }
    cout << ans << endl;
    }
    return 0;
}