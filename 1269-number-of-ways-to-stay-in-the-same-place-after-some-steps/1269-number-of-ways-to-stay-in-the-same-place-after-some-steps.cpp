class Solution {
public:
    int numWays(int steps, int arrLen) {
        int M=1e9+7;
        vector<vector<int>>dp(steps+1,vector<int>(steps+5,-1));
        function<int(int,int)>help=[&](int i,int t){
            if(i<0 || i>=arrLen || t>steps) return 0;
            if(t==steps) return i==0?1:0;
            if(dp[i][t]!=-1) return dp[i][t]%M;
            return dp[i][t]=((1LL*help(i+1,t+1)%M+1LL*help(i-1,t+1)%M+1LL*help(i,t+1)%M))%M;
        };
        return help(0,0)%M;
    }
};