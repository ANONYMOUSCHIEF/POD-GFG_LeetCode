//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int n, int k) {
        int i=0,j=n+1;
        if(k==1) return ((n>>1)+ 1 );
        while(i<j){
            if(((j-i) > k)) i+=k;
            else {
                i+=(j-i);
                return j-1;
            }
            if(j-i ==1) return i;
            if((j-i)>k) j-=k;
            else {
                j-=(j-i);
                return j+1;
            }
            if(j-i ==1) return j;
        }
       return j;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends