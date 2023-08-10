
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,n=nums.size();
        vector<vector<int>>ans;
        map<vector<int>,int>s;
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int val=nums[i]+nums[j]+nums[k];
                if(val==0){
                    s[{nums[i],nums[j],nums[k]}]=1;
                    j++,k--;
                }
                else if(val>0){
                    k--;
                }
                else j++;
            }
        }
        for(auto it:s) ans.push_back(it.first);
        return ans;

    }
};