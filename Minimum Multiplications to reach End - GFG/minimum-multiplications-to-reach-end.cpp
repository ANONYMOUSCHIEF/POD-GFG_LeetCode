//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here 
        int M=1e5;
        if(start==end) return 0;
        queue<pair<int,int>>q;
        vector<bool>vis(1e5,0);
        vector<bool>present(1e5,0);
        present[start%M]=1;
        q.push({start%M,0});
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            if(top.first==end) return top.second;
            if(vis[top.first%M]) continue;
            vis[top.first%M]=1;
            for(auto i:arr){
                int val=((top.first%M)*(i%M))%M;
                if(val) {
                    if(val== end) return top.second+1;
                    if(present[val]) continue;
                    present[val]=1;
                    q.push({val,top.second+1});
                }
            }
        }
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends