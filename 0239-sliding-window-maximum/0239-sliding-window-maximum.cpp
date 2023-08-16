class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n=arr.size();
      multiset<int> d;
       vector<int> ans(n-k+1);
       for(int i=0;i<n;i++){
           if(i>=k){
               ans[i-k]=*d.rbegin();
              auto it = d.find(arr[i-k]);
              d.erase(it);
           }
           d.insert(arr[i]);
       }
        ans[n-k]=*d.rbegin();
        return ans;
    }
};