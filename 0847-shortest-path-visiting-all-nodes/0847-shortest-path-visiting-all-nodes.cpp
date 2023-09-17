class Solution {
public:
int shortestPathLength(vector<vector<int>> &graph)
{
    int n = graph.size();
    int allVisited = (1 << n) - 1;
    queue<tuple<int,int,int>> q;
    map<pair<int,int>,bool>m;
    for(int i=0;i<n;i++){
        q.push({i,(1<<i),0});
        m[{i,(1<<i)}]=1;
    }
    while (!q.empty())
    {
        auto front = q.front();
        int v=get<0>(front),visit=get<1>(front),dis=get<2>(front);
        if(visit==allVisited) return dis;
        q.pop();
        for(auto i:graph[v]){
            int next= visit |(1<<i);
            if(m[{i,next}]) continue;
            q.push({i,next,dis+1});
            m[{i,next}]=1;
        }
    }
    return 0;
}
};