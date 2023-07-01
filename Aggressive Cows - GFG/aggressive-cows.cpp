//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
#define forj1(n) for (int j = 1; j < n; j++)
bool check(int load, vector<int> &a, int limit)
{
    int used = 1,prev=a[0];
    forj1 (a.size())
    {

        if(a[j]-prev>=load){
            used++;
            prev=a[j];
        }
    }
    return used >= limit;
}

    int solve(int n, int k, vector<int> &a) {
        sort(a.begin(),a.end());
        int low=1, high=a[n-1]-a[0],ans=0;
    while(low<=high){
        int mid=(low+high)>>1;
        if(check(mid,a,k)){
            ans=mid;
            low=mid+1;
        }
        else{
           high=mid-1;
        }
    }

    return ans;
   
    
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends