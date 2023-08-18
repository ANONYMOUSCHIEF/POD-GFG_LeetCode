class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj(n);
        for(auto i:roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<pair<int,int>>val;
        for(int i=0;i<n;i++) val.push_back({adj[i].size(),i});
        sort(val.begin(),val.end());
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               int ans=(val[i].first+val[j].first);
                for(auto i:adj[val[i].second]) if(i==val[j].second) ans--;
                maxi=max(ans,maxi);
            }
        }
        
        return maxi;
        
        
    }
};