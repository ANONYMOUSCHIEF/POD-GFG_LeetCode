class Solution {
public:
// algo()
// 1. element at pascal[row][col] is Ncr(row-1,col-1)
// 2. to print the whole row we have to like use formula fori(1,row)  ans*=(row-i);
// ans/=i;
// 3. to print all we can call step to for all rows like 1 to =rows;
 
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            vector<int>temp;
            long long val=1;
            temp.push_back(val);
            for(int j=1;j<i;j++){
                val*=(i-j);
                val/=j;
                temp.push_back(val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};