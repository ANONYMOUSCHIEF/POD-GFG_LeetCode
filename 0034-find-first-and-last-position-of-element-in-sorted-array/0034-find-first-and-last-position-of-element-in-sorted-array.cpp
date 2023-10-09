class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!nums.size()) return {-1,-1};
        int low=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if( low==nums.size() || nums[low]!=target) return {-1,-1};
        int high=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        return {low,high-1};
    }
};