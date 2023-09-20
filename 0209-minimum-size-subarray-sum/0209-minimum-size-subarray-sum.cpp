class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,sum=0,ans=nums.size()+1;
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total<target) return 0;
        while(i<n){
            sum+=nums[i];
            while(j<n && target<=sum){
                ans=min(ans,i-j+1);
                sum-=nums[j];
                j++;
            }
            i++;
        }
        return ans;
    }
};