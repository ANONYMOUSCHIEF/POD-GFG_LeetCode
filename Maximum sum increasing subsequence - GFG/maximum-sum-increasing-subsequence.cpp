//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
	    for(int prev=0;prev<n;prev++) dp[prev][prev]=arr[prev];
	    for(int i=n-1;i>=0;i--){
	        for(int prev=i;prev>=0;prev--){
	            int include=-1,exclude=-1;
	            dp[i][prev]=dp[i+1][prev];
	            if(prev == 0 || arr[i]>arr[prev-1]){
	                 dp[i][prev]=max(dp[i][prev],arr[i]+dp[i+1][i+1]);
	            }
	        }
	    }
	    return dp[0][0];
	}  
};



//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends