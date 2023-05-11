//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
    
    
public:
bool solve(vector<int>arr, int sum,int n,int index,vector<vector<int>>&dp){
    if(sum==0)
    return true;
    
    if(sum<0)
    return false;
    
    if(index>=n)
    return false;
    
    if(dp[sum][index]!=-1)
    return dp[sum][index];
    
    return dp[sum][index]=(solve(arr,sum,n,index+1,dp) || solve(arr,sum-arr[index],n,index+1,dp));
    
}
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>>dp(sum+1,vector<int>(n+1,-1));
        return solve(arr,sum,n,0,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends