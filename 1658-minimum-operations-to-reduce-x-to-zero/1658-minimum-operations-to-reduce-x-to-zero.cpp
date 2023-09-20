class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int>m;
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total==x) return nums.size();
        total-=x;
        x=total;
        int sum=0,k=0,ans=-1;
        m[0]=-1;
        for(auto i:nums){
            sum+=i;
            if(m.find(sum-x)!=m.end()){
                cout<<sum<<" "<<x<<" "<<k<<" "<<m[sum-x]<<"\n";
                ans=max(ans,k-m[sum-x]);
            }
            if(m.find(sum)==m.end()) m[sum]=k;
            k++;
        }
        if(ans==-1) return -1;
        return nums.size()-ans;
    }
};