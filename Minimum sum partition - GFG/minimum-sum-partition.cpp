//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	    int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int k=sum/2;
        vector<vector<int>>dp(n,vector<int>(k+1,0));
        for(int i=0;i<n;i++) dp[i][0]=1;
        if(nums[0]<=k) dp[0][nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                bool np=dp[i-1][j];
                bool p=0;
                if(nums[i]<=j) p=dp[i-1][j-nums[i]];
                dp[i][j]=(p||np);
            }
        }
        int mini=1e9;
        for(int i=0;i<=k;i++){
            if(dp[n-1][i]){
                mini=min(mini,abs((sum-i)-i));
            }
        }
        return mini;
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends