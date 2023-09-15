//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

bool solve(int i, int arr[],int target,vector<vector<int>>&dp){
    if(target < 0) return 0;
    if(i==0)
    return arr[0]==target ;
    if(target==0)
    return 1;
    if(dp[i][target]!=-1)return dp[i][target];
    return dp[i][target]=(solve(i-1,arr,target-arr[i],dp)||solve(i-1,arr,target,dp));
}



    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        vector<vector<int>>dp(101,vector<int>(sum,-1));
        if(sum&1)
        return 0;
        return solve(N-1,arr,sum>>1,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends