class Solution
{
public:
    int mod=1e9 + 7;
    int numOfArrays(int n, int m, int k)
    {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));
        function<int(int, int, int)> help = [&](int a, int b, int c)
        {
            if (a == n || c<0)
            {
                if (!c)
                    return 1;
                 return 0;
            }
            if (dp[a][b][c] != -1)
                return dp[a][b][c];
            int ans = 0;
            for(int i=1;i<=b;i++)
            {
                ans = (ans + help(a + 1, b, c)) % mod;
            }
             for(int i=b+1;i<=m;i++)
            {
                ans = (ans + help(a + 1, i, c - 1)) % mod;
            }
            return dp[a][b][c] = ans;
        };
        return help(0,0,k);
    }
};
