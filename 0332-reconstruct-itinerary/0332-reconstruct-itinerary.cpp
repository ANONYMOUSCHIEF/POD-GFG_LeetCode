class Solution {
public:
    vector<string>ans;
    map<string,vector<string>>adj;
    map<string,bool>visited;
    void dfs(string node){
        while(!adj[node].empty()){
            string temp=adj[node].back();
            adj[node].pop_back();
            dfs(temp);
        }
        ans.push_back(node);
        return;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto i:tickets){
            adj[i[0]].push_back(i[1]);
        }
        for(auto i:adj){
            vector<string>temp=i.second;
            sort(temp.rbegin(),temp.rend());
            adj[i.first]=temp;
        }
        // for(auto i:adj["JFK"]) cout<<i<<" ";
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};