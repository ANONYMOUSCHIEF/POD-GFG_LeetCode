//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int mod=1e9 + 7;
public:
#define ll long long int
ll factorial_modulo(ll n, ll p) {
    int result = 1;
    while (n > 1) {
        result = (result * n) % p;
        n--;
    }
    //  cout<<result<<"<-f ";
    return result;
}

ll pow_mod(ll a, ll b, ll p) {
    ll result = 1;
    while (b > 0) {
        if (b&1)
            result = (result * a) % p;
        a = (a * a) % p;
        b /= 2;
    }
    //  cout<<result<<"<-p ";
    return result;
}

ll ncr(ll n, ll r) {
    ll factorial_n = factorial_modulo(n, mod);
    ll factorial_r = factorial_modulo(r, mod);
    ll factorial_n_r = factorial_modulo(n - r, mod);
    ll inverse_r = pow_mod(factorial_r, mod-2, mod);
    ll inverse_n_r = pow_mod(factorial_n_r, mod-2, mod);
    ll result = (factorial_n * inverse_r) % mod;
    result = (result * inverse_n_r) % mod;
    // cout<<result<<" ";
    return result;
}

    ll nCr(int n, int r){
        if(n<r) return 0;
         return ncr(n,r);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends