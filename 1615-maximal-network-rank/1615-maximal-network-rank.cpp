class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj(n);
        for(auto i:roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               int ans=(adj[i].size()+adj[j].size());
                for(auto k:adj[j]) if(k==i) ans--;
                maxi=max(ans,maxi);
            }
        }
        
        return maxi;
        
        
    }
};