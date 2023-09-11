class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>>m;
        int j=0;
        for(auto i:groupSizes){
            m[i].push_back(j);
            j++;
        }
        vector<vector<int>>ans;
        for(auto i:m){
            vector<int>temp;
            int count=0;
            for(auto j:i.second){
                temp.push_back(j);
                count++;
                 if(count==i.first){
                    ans.push_back(temp);
                    count=0;
                    temp.clear();
                }
            }
        }
        return ans;
    }
};