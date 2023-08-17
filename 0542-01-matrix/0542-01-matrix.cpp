class Solution {
public:
    vector<vector<int>>dp;
    vector<vector<int>>dp2;
    int solveBottom(int n,int m,vector<vector<int>>& mat){
        if(n<0 || m<0) return 1e9;
        if(dp[n][m]!=-1) return dp[n][m];
        if(mat[n][m]==0)  dp[n][m]=0;
        int mini=1+min(solveBottom(n-1,m,mat),solveBottom(n,m-1,mat));
        dp[n][m]=min(mini,dp[n][m]);
        if(dp[n][m]==-1) dp[n][m]=mini;
        return dp[n][m];        
      }
    int solveTop(int n,int m,vector<vector<int>>&mat){
        if(n>=mat.size() || m>=mat[0].size()) return 1e9;
        if(!mat[n][m]) dp[n][m]=0;
        int mini=1+min(solveTop(n+1,m,mat),solveTop(n,m+1,mat));
        dp[n][m]=min(mini,dp[n][m]);
        if(dp[n][m]==-1) dp[n][m]=mini;
        return dp[n][m]; 
   }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        dp.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]) continue;
                dp[i][j]=1;
                int right=1e9,down=1e9;
                 if(i-1>=0) right=dp[i-1][j];
                 if(j-1>=0)  down=dp[i][j-1];
                dp[i][j]+=min(right,down);
         }
       }
         for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(!mat[i][j]) continue;
                int left=1e9,up=1e9;
                if(i+1<n) left=dp[i+1][j];
                if(j+1<m) up=dp[i][j+1];
                dp[i][j]=min(min(left,up)+1,dp[i][j]);
         }
       }
        return dp;
    }
};