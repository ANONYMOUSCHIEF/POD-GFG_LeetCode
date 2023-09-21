class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int j=0;
        int i=0;
        vector<int>a;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]>nums2[j]){
                a.push_back(nums2[j]);
                j++;
            }
            else{
                a.push_back(nums1[i]);
                i++;
            }
        }
        while(i<nums1.size()){
                a.push_back(nums1[i]);
                i++;
        }
        while(j<nums2.size()){
            a.push_back(nums2[j]);
            j++;
        }
        if((a.size()&1)==1){
            return a[(a.size())/2];
        }
        return (double)(a[a.size()/2]+a[(a.size()/2)-1])/2;
    }
};