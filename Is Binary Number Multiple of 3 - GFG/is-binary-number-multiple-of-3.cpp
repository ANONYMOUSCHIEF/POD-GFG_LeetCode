//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int convert(string s){
	    int odd=0;
	    int even =0;
	    int n=s.size()-1;
	    while(n>=0){
	        int digit=s[n]-'0';
	        if((n&1)  && digit ) odd++;
	        else if(!(n&1) && digit ) even++;
	        n--;
	    }
	    if(abs(even-odd)%3) return 0;
	    return 1;
	}	
	int isDivisible(string s){
	   return convert(s);
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends