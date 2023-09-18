class Solution {
public:
  static bool comp(vector<int>a,vector<int>b){
    int n=a.size();
    if(a[n-1]!=b[n-1])
    return a[n-1] < b[n-1];
    return  a[n-2] < b[n-2];
}

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    int t = 0;
    for (auto i : mat)
    {
        int count = 0;
        for (auto j : i)
        {
            if (j == 0)
                break;
            count++;
        }
       mat[t].push_back(t);
       mat[t].push_back(count);
        t++;
    }
    sort(mat.begin(), mat.end(), comp);
    vector<int>ans;
    t=0;
    while(k--){
        ans.push_back(mat[t][mat[0].size()-2]);
        t++;
    }
    return ans;
}
};