//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   long long solve(int i,int j,vector<int> &T,vector<int>&mn,vector<int>&mx,int usingMax, vector<vector<long long>>&dp){
       if(i==T.size()) return 0;
       
       if(dp[i][usingMax]!=-1) return dp[i][usingMax];
       
       long long mnL= abs(j-mn[T[i]]) + abs(mn[T[i]]-mx[T[i]]) + solve(i+1,mx[T[i]],T,mn,mx,1,dp);
       
       if(i==T.size()-1) mnL+=abs(mx[T[i]]-0);
       
       long long mxL= abs(j-mx[T[i]]) + abs(mx[T[i]]-mn[T[i]]) + solve(i+1,mn[T[i]],T,mn,mx,0,dp);
       if(i==T.size()-1) mxL+=abs(mn[T[i]]-0);
       
       return dp[i][usingMax]=min(mxL,mnL);
 }
  
    long long minTime(int n, vector<int> &L, vector<int> &T) {
       int size=*max_element(T.begin(),T.end());
       vector<int>mn(size+1,INT_MAX);
       vector<int>mx(size+1,INT_MIN);
       
       for(int i=0;i<n;i++){
           mn[T[i]]=min(mn[T[i]],L[i]);
           mx[T[i]]=max(mx[T[i]],L[i]);
       }
       
       set<int>S;
       
       for(int i=0;i<n;i++){
           S.insert(T[i]);
       }
       
       vector<int>A;
       for(auto i:S){
           A.push_back(i);
       }
        vector<vector<long long>>dp(A.size()+2,vector<long long>(2,-1));
       
     return solve(0,0,A,mn,mx,0,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends