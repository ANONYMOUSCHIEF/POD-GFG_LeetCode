//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &bills) {
       int vect[3]={0,0,0};
       for(int i=0;i<n;i++){
           if(bills[i]==10){
               if(vect[0]) vect[0]--;
               else return false;
               vect[1]++;
           }
           else if(bills[i]==20){
               if(vect[1] && vect[0]){
                   vect[1]--;
                   vect[0]--;
               }
               else if(vect[0]>=3){
                   vect[0]-=3;
               }
               else return false;
               vect[2]++;
           }
           else vect[0]++;
       }
       return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends