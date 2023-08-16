class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n=arr.size();
        deque<int> d;
       vector<int> ans(n-k+1);
       for(int i=0;i<n;i++){
           if(i>=k){
               ans[i-k]=d.front();
               if(arr[i-k]==d.front()) d.pop_front();
           }
           while(!d.empty() && d.back()<arr[i]){
               d.pop_back();
           }
           d.push_back(arr[i]);
           
       }
        ans[n-k]=d.front();
        return ans;
    }
};