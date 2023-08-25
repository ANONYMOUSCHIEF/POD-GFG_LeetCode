class Solution {
public:
    vector<vector<vector<int>>> dp;
    bool solve(string & s1,string &s2,string & s3,int i,int j,int k){
       if(i<0 && j<0 && k<0) return true;
        if(i>=0 && j>=0 && k>=0 && dp[i][j][k]!=-1) return dp[i][j][k];
        if(i>=0 && j>=0 && k>=0 && s1[i]==s2[j] && s1[i]==s3[k]){
           return dp[i][j][k]= (solve(s1,s2,s3,i-1,j,k-1)||solve(s1,s2,s3,i,j-1,k-1));
          
        }
        else if(i>=0 && k>=0 && s1[i]==s3[k]){
           return j>=0 ? dp[i][j][k]= solve(s1,s2,s3,i-1,j,k-1):solve(s1,s2,s3,i-1,j,k-1);
        }
        else if(j>=0 && k>=0 && s2[j]==s3[k]){
            return i>=0 ?  dp[i][j][k]= solve(s1,s2,s3,i,j-1,k-1):solve(s1,s2,s3,i,j-1,k-1);
        }
        else return (i>=0 && j>=0 && k>=0)?dp[i][j][k]= false:false;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(),m=s2.size(),l=s3.size();
        dp.resize(n, vector<vector<int>>(m, vector<int>(l, -1)));
        return solve(s1,s2,s3,n-1,m-1,l-1);
    }
};