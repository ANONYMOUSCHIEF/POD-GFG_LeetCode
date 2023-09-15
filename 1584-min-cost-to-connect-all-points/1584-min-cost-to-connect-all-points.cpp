class Solution {
public:
    class DSU
{
    vector<int> rank, parent, size;

public:
    // intialize
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i=0;i<n + 1;i++) parent[i] = i;
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
};

int minCostConnectPoints(vector<vector<int>> &points)
{
    map<pair<int, int>, int> m;
    int z = 0;
    for (auto i : points)
    {
        m[{i[0], i[1]}] = z;
        z++;
    }
    vector<tuple<int, int, int>> g;
    int l = 0;
    for (auto i : points)
    {
        int k = -1;
        for (auto j : points)
        {
            k++;
            if (l >= k) continue;
            int weight = abs(i[0] - j[0]) + abs(i[1] - j[1]);
            int u = m[{i[0], i[1]}];
            int v = m[{j[0], j[1]}];
            g.push_back({weight, u, v});
        }
        l++;
    }
    sort(g.begin(),g.end());
    DSU st (g.size());
    int ans=0;
    for(auto i:g){
        int w=get<0>(i),u=get<1>(i),v=get<2>(i);
        if(st.findpr(u)!=st.findpr(v)){
            st.unionByRank(u,v);
            ans+=w;
        }
    }
    return ans;
}
};