class Solution {
public:
     vector<pair<int,int>>serve={{100,0},{75,25},{50,50},{25,75}};
    double solve(int n1,int n2,vector<vector<double>>&dp){
        if(n1<=0 && n2<=0) return 0.5;
        if(n1<=0) return 1.0;
        if(n2<=0) return 0.0;
        if(dp[n1][n2]!=-1.0) return dp[n1][n2];
        double cal=0.0;
        for(auto i:serve){
            cal+=0.25*solve(n1-i.first,n2-i.second,dp);
        }
        return dp[n1][n2]=cal;
        
        
    }
    double soupServings(int n) {
        if(n>=5000) return 1.0;
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1.0));
        return solve(n,n,dp);
    }
};