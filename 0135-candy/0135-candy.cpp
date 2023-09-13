class Solution {
public:
    int candy(vector<int>& rating) {
        int n=rating.size();
        vector<int>val(n,1);
        for(int i=1;i<n;i++){
            if(rating[i]>rating[i-1]){
                val[i]=val[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(rating[i]>rating[i+1]){
                val[i]=max(val[i+1]+1,val[i]);
            }
        }
        int ans=accumulate(val.begin(),val.end(),0LL);
        return ans;
        
        
    }
};