//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int solve(string& a,int k){
        int n=a.size();
    	int i=0,j=0;
    	vector<int>map1(26,0);
    	int size=0;
    	long long int ans=0;
    	while(i<n){
    	    if(!map1[a[i]-'a']) size++;
    	    map1[a[i]-'a']++;
    	    while(j<=i && size>k){
    	        map1[a[j]-'a']--;
    	        if(!map1[a[j]-'a']) size--;
    	        j++;
    	    }
    	    if(j<=i) ans+=(i-j+1);
    	    i++;
    	}
    	return ans;
    }
    long long int substrCount (string&a, int k) {
    	//code here.
    	return solve(a,k)-solve(a,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends