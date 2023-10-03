class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>map1;
        for(auto i:nums){
            map1[i]++;
        }
        int ans=0;
        for(auto i:map1){
            ans+=((i.second*(i.second-1))>>1);
        }
        return ans;
    }
};