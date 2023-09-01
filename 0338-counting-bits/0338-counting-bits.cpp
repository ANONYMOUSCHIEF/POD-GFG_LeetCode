class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int k=0,count=0;
            while(k<32){
                if(i & (1<<k)) count++; 
                k++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};