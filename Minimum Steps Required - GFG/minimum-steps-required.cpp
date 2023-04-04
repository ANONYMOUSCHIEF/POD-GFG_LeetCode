//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int solve(string str,char c){
    int count=0,ans=0;
    for(int i=0;i<str.length();i++){
        if(str[i]==c &&!count){
            count++;
            ans++;
        }
        if(str[i]==c)
        count++;
        else
        count=0;
    }
    return ans;
}


int minSteps(string str) {
    
    return min(solve(str,'a'),solve(str,'b'))+1;
    
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends