//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

int  solve(int m,int n){
    if(m==0 && n==0)return 1;
    if(m<0 || n<0) return 0;
    
    return solve(m-1,n)+solve(m,n-1);
}
long long  numberOfPaths(int m, int n)
{
   return solve(m-1,n-1);
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends