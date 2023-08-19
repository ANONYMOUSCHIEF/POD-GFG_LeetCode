#define vi vector<int>
#define rep(s,e,i) for(int i=s;i<e;i++)

class DSU
{
    vi rank, parent, size;

public:
    // intialize
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rep(0, n + 1, i) parent[i] = i;
    }
    // path compression
    int findpr(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findpr(parent[u]);
    }

    // union
    void unionByRank(int u, int v)
    {
        int ulp_u = findpr(u);
        int ulp_v = findpr(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findpr(u);
        int ulp_v = findpr(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    int maxSize()
    {
        return *max_element(size.begin(), size.end());
    }
};

static bool comp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
};

class Solution
{
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        rep(0, edges.size(), i) edges[i].push_back(i);
        sort(edges.begin(), edges.end(), comp);
        DSU ds(n);
        int normal = 0;
        for (auto i : edges)
        {
            if (ds.findpr(i[0]) != ds.findpr(i[1]))
            {
                normal += i[2];
                ds.unionBySize(i[0], i[1]);
            }
        }
        cout << normal << "\n";
        vector<vector<int>> ans(2);
        rep(0, edges.size(), i)
        {
            int left = 0;
            DSU ds1(n);
            rep(0, edges.size(), j)
            {
                if (i != j && ds1.findpr(edges[j][0]) != ds1.findpr(edges[j][1]))
                {
                    left += edges[j][2];
                    ds1.unionBySize(edges[j][0], edges[j][1]);
                }
            }
            if (ds1.maxSize() < n || left > normal)
            {
                ans[0].push_back(edges[i][3]);
            }
            else
            {
                int include = 0;
                DSU ds2(n);
                ds2.unionBySize(edges[i][0], edges[i][1]);
                include += edges[i][2];
                rep(0, edges.size(), j)
                {
                    if (i != j && ds2.findpr(edges[j][0]) != ds2.findpr(edges[j][1]))
                    {
                        include += edges[j][2];
                        ds2.unionBySize(edges[j][0], edges[j][1]);
                    }
                }
                if (include == normal)
                    ans[1].push_back(edges[i][3]);
            }
        }
        return ans;
    }
};
