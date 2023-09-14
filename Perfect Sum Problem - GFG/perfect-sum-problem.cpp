//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod=1e9+7;
	public:
	int solve(int arr[], int n, int sum,vector<vector<int>>&dp){
	    if(n==0){
	        if(arr[n]==0 && sum==0)
	        return 2;
	        if(arr[n]==sum || sum==0)
	        return 1;
	        return 0;
	    }
	    if(dp[n][sum]!=-1)
	    return dp[n][sum];
	    
	    int take=0,notTake=0;
	    if(sum>=arr[n]){
	       take=solve(arr,n-1,sum-arr[n],dp);
	    }
	    notTake=solve(arr,n-1,sum,dp);
	    return dp[n][sum]=((take%mod)+(notTake%mod))%mod;
	    
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,n-1,sum,dp);
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends