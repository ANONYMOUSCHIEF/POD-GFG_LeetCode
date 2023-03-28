//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string s)
    {
        int countS=0;
        int countB=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            countS=0;
            countB=0;
            if(s[i]>='a' && s[i]<='z')
            countS+=1;
            else
            countB+=1;
            for(int j=i+1;j<s.length();j++){
                if(s[j]>='a' && s[j]<='z')
                countS+=1;
                else
                countB+=1;
                
                if(countS==countB)
                ans+=1;
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
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends