//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int b(int l,int r,int a[]){
	    int n=r;
	    while(l<=r){
	        int mid=(l+r)>>1;
	        if(mid==0 || (a[mid-1]<=a[mid]) && (mid==n || a[mid+1]<=a[mid]))
	        return a[mid];
	        
	        if(mid>0 && a[mid-1]>a[mid]){
	            r=mid-1;
	        }
	        else{
	            l=mid+1;
	        }
	    }
	}
	int findMaximum(int arr[], int n) {
	   return b(0,n-1,arr);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends