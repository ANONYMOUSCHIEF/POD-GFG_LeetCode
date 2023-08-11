//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
//   long long int solve(int n,int sum,int a[]){
//       if(sum==0) return 1LL;
//       if(n == 0) return !(sum%a[0]);
//       if(dp[n][sum]!=-1) return dp[n][sum];
//       long long int take=0;
//       if(sum>=a[n]){
//           take = solve(n,sum-a[n],a);
//       }
//       long long int notTake=solve(n-1,sum,a);
//       return dp[n][sum]=(take + notTake);
//       }
    long long int count(int a[], int N, int sum) {
        vector<vector<long long int>>dp(N,vector<long long int>(sum+1,0));
        for(int i=0;i<N;i++) dp[i][0]=1;
        
        for(int i=1;i<=sum;i++) dp[0][i]=!(i%a[0]);
        
        for(int i=1;i<N;i++){
            for(int j=0;j<=sum;j++){
                 long long int take=0;
                  if(j>=a[i]){
                      take = dp[i][j-a[i]];
                  }
                  long long int notTake=dp[i-1][j];
                  dp[i][j]=(take + notTake);
            }
        }
        
        return dp[N-1][sum];
        // return solve(N-1,sum,coins);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends