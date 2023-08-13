//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int M=1000000007;
    int nthFibonacci(int n){
        // code here
        vector<long long int>dp(n+1,0);
         dp[0]=0;
         dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=((dp[i-1]%M)+(dp[i-2]%M))%M;
        }
        return (dp[n]%M);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends