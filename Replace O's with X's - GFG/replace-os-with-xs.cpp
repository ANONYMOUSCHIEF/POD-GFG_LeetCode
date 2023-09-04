//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{
public:
    map<pair<int,int>,bool>m;
    vector<pair<int,int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
    
    void dfs(int r,int c,vector<vector<char>>&mat){
        int n=mat.size(),z=mat[0].size();
        m[{r,c}]=1;
        for(auto i:dir){
            int nr=r+i.first,nc=c+i.second;
            if(nr>=0 && nr<n && nc>=0 && nc<z && mat[nr][nc]=='O' && !m[{nr,nc}]){
                dfs(nr,nc,mat);
            }
        }
    }
    
    
    vector<vector<char>> fill(int n, int t, vector<vector<char>> mat)
    {
       int r=0,c=0;
        for(auto i:mat){
            c=0;
            for(auto j:i){
                if((r==0 || r==n-1 || c==0 || c==t-1) && j=='O' && !m[{r,c}]){
                    dfs(r,c,mat);
                }
                c++;
            }
            r++;
        }
        r=0,c=0;
        for(auto i:mat){
            c=0;
            for(auto j:i){
                if(j=='O' && !m[{r,c}]){
                   mat[r][c]='X';
                }
                c++;
            }
            r++;
        }
        
        return mat;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends