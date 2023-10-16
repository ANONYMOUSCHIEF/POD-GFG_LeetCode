class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<int>a;
        long long c=1;
        for(int i=1;i<=rowIndex;i++){
            a.push_back(c);
            c=c*(rowIndex-i)/i;
        }
        return a;
    }
};