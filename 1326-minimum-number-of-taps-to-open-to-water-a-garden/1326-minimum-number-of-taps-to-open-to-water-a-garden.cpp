class Solution {
public:
    vector<int>dp;
   int help(int i,vector<pair<int,int>>&interval){
        int n=interval.size()-1;
        if((interval[i].second)==n) return 1;
        if(i==interval.size()) return 1e9;
        if(dp[i]!=-1) return dp[i];
        int take=1e9,notTake=1e9;
       for(int j=i+1;j<=n;j++){
           if(interval[i].second>=interval[j].first) {
             take=min(take,1+help(j,interval));
             }
           else break;
       }
        
        return dp[i]=take;
        
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>>interval;
        dp.resize(n+1,-1);
        int j=0;
        for(auto i:ranges){
            interval.push_back({max(0,j-i),min(n,i+j)});
            j++;
        }
        sort(interval.begin(),interval.end());
        int ans=1e9;
        for(int i=0;i<interval.size();i++){
            if(interval[i].first==0){
                ans=min(ans,help(i,interval));
            }
        }
        if(ans==1e9) return -1;
        return ans;
        
    }
};