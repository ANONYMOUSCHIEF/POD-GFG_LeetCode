class Solution {
public:
    int minOperations(vector<int>& A) {
        set<int>s;
        int n=A.size(),ans=n;
        for(auto i:A){
            s.insert(i);
        }
        vector<int>newV;
        for(auto i:s){
            newV.push_back(i);
        }
        for(int i=0;i<newV.size();i++){
            int mini=newV[i];
            int maxi=mini+n-1;
            int j=upper_bound(newV.begin(),newV.end(),maxi)-newV.begin();
            ans=min(ans,n-j+i);
        }
        return ans;
    }
};