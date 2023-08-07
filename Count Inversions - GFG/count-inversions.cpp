//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    #define ll long long int
    #define vi vector<ll>
    ll val=0;
    vi merge(vi left, vi right)
{
    vi ans;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            ans.push_back(left[i]);
            i++;
        }
        else
        {
            val += (left.size() - i);
            ans.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size())
    {
        ans.push_back(left[i]);
        i++;
    }

    while (j < right.size())
    {
        ans.push_back(right[j]);
        j++;
    }
    return ans;
}

vi mergeSort(vi &a, int low, int high)
{
    if (low == high)
    {
        return {a[low]};
    }
    int mid = (low + high) >> 1;
    vi left = mergeSort(a, low, mid);
    vi right = mergeSort(a, mid + 1, high);
    return merge(left, right);
}
    long long int inversionCount(long long arr[], long long N)
    {
        vi a;
        for(int i=0;i<N;i++){
            a.push_back(arr[i]);
        }
        mergeSort(a,0,N-1);
        return val;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends