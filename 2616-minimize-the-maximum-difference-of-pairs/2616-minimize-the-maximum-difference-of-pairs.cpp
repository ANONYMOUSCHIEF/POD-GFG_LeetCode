class Solution {
public:
    bool check (int val,vector<int>&a,int limit){
        int count=0;
        for(int i=0;i<a.size();i++){
            if( i+1 < a.size() &&  a[i+1]-a[i]<=val) {
                i++;
                count++;
            }
         }
        return count>=limit;
     }
    int minimizeMax(vector<int>& a, int p) {
        sort(a.begin(),a.end());
        int low=0,high=1e9;
        while(low<=high){
            int mid=(low+high)>>1;
            if(check(mid,a,p)){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
        
    }
};