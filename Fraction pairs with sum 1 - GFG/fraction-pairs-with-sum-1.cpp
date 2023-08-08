//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int num[], int den[])
    {
        vector<pair<int,int>>a;
        for(int i=0;i<n;i++){
            int val=__gcd(num[i],den[i]);
            a.push_back({num[i]/val,den[i]/val});
        }
        int count=0;
        map<pair<int,int>,int>m;
        // for(auto i:a){
        //     cout<<i.first<<" "<<i.second<<" "<<i.second-i.first<<" "<<i.second<<"\n";
        // }
        
        for(auto i:a){
                count+= m[{i.second-i.first,i.second}];
                m[{i.first,i.second}]+=1;
        }
        return count;
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends