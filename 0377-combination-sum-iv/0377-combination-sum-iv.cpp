class Solution {
public:
    vector<int>dp;
    int help(vector<int>&a,int sum){
        if(sum<0) return 0;
        if(sum==0) return 1;
        if(dp[sum]!=-1) return dp[sum];
        dp[sum]=0;
        for(auto x:a){
            dp[sum]+=(help(a,sum-x));
        }
        return dp[sum];
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1,-1);
        int ans=help(nums,target);
        return ans;
    }
};