class Solution {
public:
    
    int countOrders(int n) {
        int mod=1e9+ 7;
        int res=1;
        for(int i=1;i<=n;i++) res=(1LL*(res%mod)*i)%mod;
        for(int i=1;i<2*n;i+=2) res=( 1LL*res%mod * i%mod)%mod;
        return res;
        
    }
};