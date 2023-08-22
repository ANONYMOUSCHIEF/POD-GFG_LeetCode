//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define rep(s,n,i) for(int i=s;i<n;i++)
class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > a, int n)
    {
       vector<int>row(n),col(n);
       int maxi=INT_MIN;
       rep(0,n,i){
           int colSum=0,rowSum=0;
           rep(0,n,j){
               rowSum+=a[i][j];
               colSum+=a[j][i];
           }
           row[i]=rowSum;
           col[i]=colSum;
           maxi=max({maxi,rowSum,colSum});
       }
       int ans=0;
       rep(0,n,i){
           rep(0,n,j){
               int mini=min(maxi-row[i],maxi-col[j]);
               row[i]+=mini;
               col[j]+=mini;
               ans+=mini;
           }
       }
       return ans;
       
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends