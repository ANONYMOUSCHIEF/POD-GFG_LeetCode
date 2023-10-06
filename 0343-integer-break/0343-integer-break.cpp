class Solution {
public:
    int integerBreak(int n) {
        int ans=n-1;
        for(int i=1;i<=n;i++){
             int po=n/i;
             for(int k=1;k<=po;k++){
                 int j=n-(k*i);
                 ans= max(ans,(int)pow(i,k)*j);
             }
             
        }
        return ans;
    }
};