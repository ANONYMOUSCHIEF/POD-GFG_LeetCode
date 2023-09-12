class Solution {
public:
    int minDeletions(string s) {
        vector<int>a(26,0);
        for(auto i:s){
            a[i-'a']++;
        }
        sort(a.rbegin(),a.rend());
        // for(auto i:a) cout<<i<<" ";
        int ans=0;
        int smallest=INT_MAX;
        for(auto i:a){
            if(i==0) break;
            if(smallest>i) {smallest=i; continue;}
            else {
                ans+=(i-smallest+1);
                if(!smallest){ ans--; continue;}
                smallest=i-(i-smallest+1);
            }
        }
        return ans;
    }
};