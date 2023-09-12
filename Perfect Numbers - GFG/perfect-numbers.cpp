//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        if(N==1) return 0;
        long long  ans=N;
        long long  num=N;
       for(int i=2;i<sqrt(N);i++){
           if(N%i) continue;
           ans-=i;
           ans-=(num/i);
       }
       ans-=1;
       return !ans;
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends