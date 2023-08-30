class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        int i=n-2;
        while(i>=0){
            int val=ceil(nums[i]/(nums[i+1]*1.0));
            ans+=(val-1);
            nums[i]/=val;
            i--;
        }
        return ans;
    }
};