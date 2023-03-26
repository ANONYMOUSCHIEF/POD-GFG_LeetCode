//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool help(int v,vector<int> adj[],vector<bool>& visited,vector<bool> &stack){
        if(stack[v])
        return true;
        if(visited[v])
        return false;
        visited[v]=1;
        stack[v]=1;
        for(auto i:adj[v]){
            if(help(i,adj,visited,stack))
            return true;
        }
        stack[v]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // cout<<adj->size()<<endl;
        vector<bool>stack(V,false);
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
             if (help(i,adj,visited,stack)) 
             return true;
        }
        return false;
       
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends