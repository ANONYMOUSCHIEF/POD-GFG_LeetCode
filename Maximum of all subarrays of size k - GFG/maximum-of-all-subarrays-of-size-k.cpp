//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
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

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends