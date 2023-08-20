//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
       int ans=0;
       vector<pair<int,int>>dir={{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
      for(int i=0;i<matrix.size();i++){
          for(int j=0;j<matrix[i].size();j++){
              if(matrix[i][j]){
                  int count=0;
                  for(auto k:dir){
                      int newj=(j+k.second);
                      int newi=(i+k.first);
                      if(newi>=0 && newi<matrix.size() && newj>=0 && newj<matrix[i].size() && !matrix[newi][newj])count++;
                  }
                  if(count && !(count&1)) ans++; 
              }
              }
          }
          return ans;
      }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends