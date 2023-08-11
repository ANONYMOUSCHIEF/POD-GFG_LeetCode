class Solution {
public:
int val=0;
void help(vector<int> &a, int l, int mid, int r)
{
    vector<int> ans;
    int i = l, j = mid+1;
    while (i <= mid && j <= r)
    {
        if(1LL*a[i]>(2LL*a[j])) val+=(mid-i+1),j++;
        else i++;   
    }
    i=l,j=mid+1;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            ans.push_back(a[i]);
            i++;
        }
        else{
            ans.push_back(a[j]);
            j++;
        }
            
    }

    while (i <= mid)
    {
        
        ans.push_back(a[i]);
        i++;
    }
    while (j <= r)
    {

        ans.push_back(a[j]);
        j++;
    }
    int k = 0;
    for (int i = l; i <= r; i++)
    {
        a[i] = ans[k++];
    }
}

void  merge(vector<int> &a, int l, int r)
{
    
    if (l >= r) return ;
    int mid = (l + r) >> 1;
    merge(a, l, mid);
    merge(a, mid+1, r);
    help(a, l, mid, r);
}
    int reversePairs(vector<int>& nums) {
        merge(nums,0,nums.size()-1);
        return val;
    }
};