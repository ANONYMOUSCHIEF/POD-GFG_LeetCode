class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++) pref[i]=min(pref[i-1],nums[i]);
        stack<int>sta1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>pref[i]){
                while(!sta1.empty() && sta1.top()<=pref[i]) sta1.pop();
                if(!sta1.empty() && sta1.top()<nums[i]) return true;
                sta1.push(nums[i]);
            }
        }
        return false;
    }
};