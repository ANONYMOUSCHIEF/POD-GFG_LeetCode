class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        vector<int>x;
        int xo=0;
        for(auto i:arr2){
           xo^=i;
        }
        for(auto i:arr1){
            x.push_back(i&xo);
        }
        int ans=0;
        for(auto i:x){
            ans^=i;
        }
        return ans;
    }
};