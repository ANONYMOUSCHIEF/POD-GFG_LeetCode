//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //You need to complete this fucntion
    
    long long pow_mod(long long a, long long b, long long p) {
    long long maxi = 1;
    while (b > 0) {
        if (b&1)
            maxi = (maxi * a) % p;
        a = (a * a) % p;
        b /= 2;
    }
    return maxi;
}
    long long power(int N,int R)
    {
       string s=to_string(N);
       reverse(s.begin(),s.end());
       long long power=stoi(s);
       long long p=1e9+7;
       return pow_mod(N,power,p);
        
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends