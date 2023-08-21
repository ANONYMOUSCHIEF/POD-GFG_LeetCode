class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        string temp="";
        for(int i=0;i<n;i++){
            temp+=s[i];
            int flag=0;
            for(int j=i+1;j<n;j++){
                if(s.substr(j,temp.length())==temp){
                    j+=temp.length();
                    j--;
                    flag=1;
                }
                else {
                    flag=0;
                    break;
                }
            }
            if(flag) return true;
         }
        return false;
    }
};