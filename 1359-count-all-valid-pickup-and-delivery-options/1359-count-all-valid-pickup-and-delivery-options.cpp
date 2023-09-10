class Solution {
public:
    
    int countOrders(int n) {
        int mod=1e9+ 7;
        int res=1;
        for(int i=1;i<=n;i++) res = (1LL * res * i * (2*i-1))%mod;
        return res;
        
    }
};