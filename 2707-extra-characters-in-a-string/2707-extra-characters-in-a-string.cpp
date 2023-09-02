class Solution {
public:
    map<string,bool> present;
    vector<int>dp;
    int solve(int i,string &s){
        if(i>=s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int op1=1+solve(i+1,s);
        string k="";
        for(int j=i;j<s.size();j++){
            k+=s[j];
            if(present[k]){
                op1=min(op1,solve(j+1,s));
            }
        }
        return dp[i]=op1;
        
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto i:dictionary) present[i]=1;
        dp.resize(s.size()+1,-1);
        return solve(0,s);
    }
};