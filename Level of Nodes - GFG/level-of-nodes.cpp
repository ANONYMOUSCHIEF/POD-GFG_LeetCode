//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int X)
    {
        queue<int> q;
        int level = 0;
        q.push(0);
        vector<int> visited(V + 1, 0);
        while (!q.empty())
        {
            int size = q.size();
            level++;
            while (size--)
            {
                int top = q.front();
                if (X == top)
                    return level-1;
                q.pop();
                for (auto i : adj[top])
                {
                    if (visited[i])
                        continue;
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends