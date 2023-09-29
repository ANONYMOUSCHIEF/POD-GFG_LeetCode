//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};

        function<void(int, int)> dfs = [&](int x, int y)
        {
            grid[x][y] = 2;
            for(auto i:dir){
                int newX=x+i.first,newY=y+i.second;
                if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==1){
                    dfs(newX,newY);
                }
            }
        };

        for (int i = 0; i < m; i++)
        {
            if(grid[0][i]==1){
                dfs(0,i);
            }
            if(grid[n-1][i]==1){
                dfs(n-1,i);
            }
        }

        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(i,0);
            }
            if(grid[i][m-1]==1){
                dfs(i,m-1);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count+=(grid[i][j]==1);
            }
        }

        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends