class Solution {
public:
    bool static comp(vector<int>a,vector<int>b){
        if(a[1]!=b[1]) return a[1]<b[1];
        return a[0]<b[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
       sort(pairs.begin(), pairs.end(),comp);
        vector<vector<int>>ans;
    int maxi = 0;
        ans.push_back(pairs[0]);
    for (int i = 1; i < pairs.size(); i++)
    {
        if (ans.back()[1] >= pairs[i][0]) continue;
        else
            ans.push_back(pairs[i]);
    }
    return ans.size();
    }
};