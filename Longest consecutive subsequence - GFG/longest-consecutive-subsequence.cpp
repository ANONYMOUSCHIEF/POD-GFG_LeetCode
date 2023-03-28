//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      vector<int>a(1e6+1,0);
      for(int i=0;i<n;i++){
          a[arr[i]]+=1;
      }
      int maxCount=0;
      int count=0;
      for(int i=0;i<1e6;i++){
          if(a[i])
          count++;
          else{
              maxCount=max(maxCount,count);
              count=0;
          }
      }
      maxCount=max(maxCount,count);
      return maxCount;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends