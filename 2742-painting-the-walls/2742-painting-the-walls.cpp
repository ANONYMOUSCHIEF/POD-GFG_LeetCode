class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        function<int(int,int)>help=[&](int i,int k){
            if(k>=n) return 0;
            if(i==n) return (int)1e9; 
            if(dp[i][k]!=-1) return dp[i][k];
            return dp[i][k]=min(cost[i]+help(i+1,k+time[i]+1),help(i+1,k));
        };
        return help(0,0);
    }
};