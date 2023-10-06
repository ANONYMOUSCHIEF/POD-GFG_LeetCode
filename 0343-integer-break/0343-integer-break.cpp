class Solution
{
public:
    int integerBreak(int n)
    {
        if(n<=3) return n-1;
        vector<int> dp(n + 1, -1);
        function<int(int)> help = [&](int n)
        {
            if (n <= 3)
                return n;
            if (dp[n] != -1)
                return dp[n];
            int ans = n;
            for (int i = 2; i < n; i++)
            {
                ans = max(ans, i * help(n - i));
            }
            return dp[n] = ans;
        };
        return help(n);
    };
};