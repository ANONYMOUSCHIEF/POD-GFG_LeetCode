class Solution {
public:
int solve(int m,int n,vector<vector<int>>&dp){
    if(m==0 && n==0 ) return 1;
    if(m<0 || n<0) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    return dp[m][n]=solve(m-1,n,dp)+solve(m,n-1,dp);
}
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        vector<int>prev(n+1,0);
        prev[0]=1;
        for(int i=0;i<m;i++){
            vector<int>temp(n+1,0);
            for(int j=0;j<n;j++){
               temp[j]+=prev[j];
                if(j-1>=0)
                temp[j]+=temp[j-1];
            }
            prev=temp;
        }
        return prev[n-1];
        // return dp[m-1][n-1];
        // return solve(m-1,n-1,dp);
    }
};