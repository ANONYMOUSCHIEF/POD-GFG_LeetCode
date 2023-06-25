//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int a[MAX][MAX],int row,int col)
    {
       unordered_map<string,int>m;
       vector<string>b;
        vector<vector<int>>ans;
        for(int i=0;i<row;i++){
            string temp="";
            for(int j=0;j<col;j++){
                temp+=('0'+a[i][j]);
                temp+=" ";
            }
            if(!m[temp]) {
                m[temp]=1;
                b.push_back(temp);
            }
        }
        for(auto i:b){
          cout<<i<<"$";
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends