class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string temp="";
        int n=s.length(),m=t.length();
         int count=0;
        int i=n-1;
        while(i>=0){
            if(s[i]=='#'){
                while(i>=0 && s[i]=='#'){
                    count++;
                    i--;
                }
            }
            else if(count) count--,i--;
            else temp+=s[i],i--;
        }
        string temp2=temp;
        temp="";
        count=0;
        i=m-1;
        while(i>=0){
            if(t[i]=='#'){
                while(i>=0 && t[i]=='#'){
                    count++;
                    i--;
                }
            }
            else if(count) count--,i--;
            else temp+=t[i],i--;
        }
        // cout<<temp<<" "<<temp2;
        return temp==temp2;
    }
};