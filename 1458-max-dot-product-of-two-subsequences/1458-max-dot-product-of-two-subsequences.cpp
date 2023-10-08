class Solution
{
public:
    int maxDotProduct(vector<int> &a, vector<int> &b)
    {
        int n=a.size(),m=b.size();
        int maxi1 = *max_element(a.begin(), a.end());
        int mini1 = *min_element(a.begin(), a.end());
        int maxi2 = *max_element(b.begin(), b.end());
        int mini2 = *min_element(b.begin(), b.end());
        if (maxi1 < 0 && mini2>0)
            return maxi1 * mini2;
        if (maxi2 < 0 && mini1>0)
            return maxi2 * mini1;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        function<int(int, int)> help = [&](int i, int j)
        {
            if (i < 0 || j < 0)  return 0;
            if (dp[i][j] != -1)
                return dp[i][j];
            dp[i][j] = max({a[i] * b[j] + help(i - 1, j - 1), help(i - 1, j), help(i, j - 1)});
            return dp[i][j];
        };
        return help(n-1,m-1);
    }
};