//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define rep(s,e,i) for(int i=s;i<e;i++)

class Solution
{
public:
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
        set<vector<int>> s;
        rep(0, n, i)
        {
            rep(0, m, j)
            {
                
                for (auto k : dir)
                {
                    int x = i, y = j;
                    string temp;
                    temp.push_back(grid[x][y]);
                    while (temp.size() != word.size())
                    {
                        x += k.first, y += k.second;
                        if (x < 0 || x>= n || y < 0 || y >= m)
                        {
                            break;
                            
                        }
                       temp.push_back(grid[x][y]);
                    }
                    if (temp == word)
                        s.insert({i, j});
                }
            }
        }
        vector<vector<int>> ans;
        for (auto i : s)
        {
            ans.push_back(i);
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends