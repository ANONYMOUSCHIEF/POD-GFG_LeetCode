class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total==x) return n;
        total-=x;
        x=total;
        int j=0,k=0,ans=-1,sum=0;
        for(auto i:nums){
            sum+=i;
            while(k<n && sum>x){
                sum-=nums[k];
                k++;
            }
            if(sum==x) ans = max(ans,j-k);
            j++;
        }
        if(ans==-1) return -1;
        return n-ans-1;
    }
};