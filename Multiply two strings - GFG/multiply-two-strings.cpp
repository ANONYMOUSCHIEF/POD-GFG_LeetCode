//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        int p1=0;
        int neg=0;
        if(s1[0]=='-' && s2[0]=='-') {
             s1.erase(s1.begin());
             s2.erase(s2.begin());
        }
        else if(s1[0]=='-'){
            neg=1;
            s1.erase(s1.begin());
        }
        else if(s2[0]=='-'){
            neg=1;
             s2.erase(s2.begin());
        }
        while(s1.size() && s1[p1]=='0') s1.erase(s1.begin());
        while(s2.size() && s2[p1]=='0') s2.erase(s2.begin());
        if(!s1.size() || !s2.size()) return "0";
        int i=s1.size(),j=s2.size();
        string ans;
        for(int k=0;k<i+j;k++) ans.push_back('0');
        i--,j--;
        // return "1";
        p1=0;
        int carry=0;
        while(i>=0){
            int p2=0,carry=0;
            int d1=s1[i]-'0';
           
            j=s2.size()-1;
            while(j>=0){
                int d2=(s2[j]-'0');
                int sum = (d1*d2) + (ans[p1+p2]-'0') + carry;
                carry=sum/10;
                ans[p1+p2]=((sum%10)+'0');
                // cout<<ans[p1+p2]<<" ";
                p2++;
                j--;
            }
            ans[p1+p2]=((ans[p1+p2])+(carry));
             p1++;
             i--;
        }
        while(ans.size() && ans[ans.size()-1]=='0') ans.erase(ans.size()-1);
        if(neg) ans.push_back('-');
        reverse(ans.begin(),ans.end());
        return ans;
        
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends