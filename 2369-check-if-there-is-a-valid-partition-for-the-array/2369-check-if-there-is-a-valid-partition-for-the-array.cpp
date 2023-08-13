class Solution {
public:
    vector<int>dp;
    bool solve(int i,vector<int>&nums){
        if(i<0) return true; 
        cout<<nums[i]<<" "<<i<<" ";
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        if(i>0 && (nums[i-1]==nums[i])){
            ans|=solve(i-2,nums);
        }
        
        if(i>1 &&( (nums[i]==nums[i-1]) && (nums[i]==nums[i-2]))){
            ans|=solve(i-3,nums);
        }
        
        if(i>1 && ((nums[i]==(nums[i-1]+1)) && ((nums[i-2]+2)==nums[i]))){
            ans|=solve(i-3,nums);
        }
        return dp[i]=ans;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,-1);
       bool val= solve(n-1,nums);
        // for(auto i:dp) cout<<i<<" ";
       return val;
    }
};