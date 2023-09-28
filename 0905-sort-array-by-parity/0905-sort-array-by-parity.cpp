class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        int n=a.size();
        int i=0,j=n-1;
        while(i<=j){
            if((a[i]&1) &&  !(a[j]&1) ) swap(a[i],a[j]),i++,j--;
            else if(!(a[i]&1)) i++;
            else if((a[j]&1)) j--;
        }
        return a;
    }
};