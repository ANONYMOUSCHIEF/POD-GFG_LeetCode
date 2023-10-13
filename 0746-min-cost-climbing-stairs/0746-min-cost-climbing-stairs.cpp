class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        cost.push_back(0);
        vector<int>dp(n+1,-1);
        function<int(int)>help=[&](int n){
            if(n==0 || n==1) return cost[n];
            if(dp[n]!=-1) return dp[n];
            return dp[n]=cost[n]+min(help(n-1),help(n-2));
        };
        return help(n);
    }
};