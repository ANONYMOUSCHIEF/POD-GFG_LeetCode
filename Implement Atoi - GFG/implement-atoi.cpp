//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
       int n=str.length()-1;
       int num=0,power=1;
      if(str[0]=='-'){
          
      }
       for(int i=n;i>=0;i--){
           
           if(i==0 && str[i]=='-'){
               continue;
           }
           if(!(str[i]>='0' && str[i]<='9'))
           return -1;
           int digit=str[i]-'0';
           num+=digit*power;
           power*=10;
       }
       
       return str[0]=='-'?-num:num;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends