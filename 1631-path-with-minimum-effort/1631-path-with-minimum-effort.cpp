class Solution {
public:
  int minimumEffortPath(vector<vector<int>> &heights)
{
    int n = heights.size(), m = heights[0].size();
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    vector<vector<int>> dis(n, vector<int>(m, INT32_MAX));
    q.push({0, 0, 0});
    int mini = INT_MAX;
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty())
    {
        auto top = q.top();
        int val= get<0>(top);
        int x= get<1>(top);
        int  y= get<2>(top);
        if ((x == n - 1) && (y == m - 1))
            return val;
        q.pop();
        if (val > dis[x][y])
            continue;
        for (auto j : dir)
        {
            int newX = x + j.first;
            int newY = y + j.second;
            if (newX < 0 || newX >= n || newY < 0 || newY >= m)
                continue;
            int newVal = max(val, abs(heights[newX][newY] - heights[x][y]));
            if (dis[newX][newY] > newVal)
            {
                dis[newX][newY] = newVal;
                q.push({newVal, newX, newY});
            }
        }
    }
    return -1;
}
};