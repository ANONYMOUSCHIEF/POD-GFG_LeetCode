//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int KS(int W, int wt[], int val[], int n,vector<vector<int>>& dp){
        int result=0,c1,c2;
       if(n<0){
           return 0;
       }
       if(dp[n][W]!=-1){
            return dp[n][W];
        }
       if(wt[n]>W){
          result=KS(W,wt,val,n-1,dp);
          
      }
      else{
          c1=KS(W,wt,val,n-1,dp);
          c2=val[n]+KS(W-wt[n],wt,val,n-1,dp);
          result=max(c1,c2);
      }
      dp[n][W]=result;
      return dp[n][W] ;
      
      
       
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //   int result=0,c1,c2;
    //   if(n==0 || W==0){
    //       return result;
    //   }
       
    //   else if(wt[n]>W){
    //       result=knapSack(W,wt,val,n-1);
    //   }
    //   else{
    //       c1=knapSack(W,wt,val,n-1);
    //       c2=val[n]+knapSack(W-wt[n],wt,val,n-1);
    //       result=max(c1,c2);
    //   }
    vector<vector<int>> dp( n+1 , vector<int> (W+1, -1)); 
       return KS(W,wt,val,n-1,dp);
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends