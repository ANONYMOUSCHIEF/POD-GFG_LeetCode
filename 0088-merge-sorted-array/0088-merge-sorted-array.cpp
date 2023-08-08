class Solution {
public:
    void merge(vector<int>& a, int n, vector<int>& b, int m) {
       int len=(n+m);
       int gap=(len>>1) + ( len&1);
       while(gap>0){
           int left=0,right=left+gap;
           while(right<len){
//                
               if(left<n && right>=n){
                   if(a[left]>b[right-n]){
                       swap(a[left],b[right-n]);
                    }
                }
               else if(left>=n){
                   if(b[left-n]>b[right-n]){
                       swap(b[left-n],b[right-n]);
                    }
                }
               else{
                    if(a[left]>a[right]){
                       swap(a[left],a[right]);
                    }
                }
               left++,right++; 
            }
           if(gap==1) break;
           gap=(gap>>1) + (gap&1);
       }
       //  for(auto j:b) cout<<j<<" ";
       int i=n,j=0;
        while(i<len && j<m) a[i++]=b[j++];
        
    }
};