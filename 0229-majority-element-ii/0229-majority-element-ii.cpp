class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0,e1=-1,e2=-1;
        for(int i:nums){
            if(cnt1==0 && e2!=i){
                e1=i;
            }
            
            if(cnt2==0 && e1!=i){
                e2=i;
             }
            if(i==e1) cnt1++;
            else if(i==e2) cnt2++;
            else cnt1--,cnt2--; 
        }
       cnt1=0,cnt2=0;
        for(int i:nums){
            if(i==e1) cnt1++;
            if(i==e2) cnt2++;
        }
        int n=nums.size();
       if(cnt1>(n/3) && cnt2>(n/3) && e1!=e2) return {e1,e2};
       if(cnt1>(n/3)) return {e1};
       if(cnt2>(n/3)) return {e2};
        return {};
    }
};