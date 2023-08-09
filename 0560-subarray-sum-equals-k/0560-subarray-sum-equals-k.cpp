class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
    unordered_map<long long,int>m;
    long long sum=0;
    int ans=0;
    int maxi=0;
    m[0]=1;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        ans+=m[sum-k];
        m[sum]+=1;
    }
   return ans;
    }
};