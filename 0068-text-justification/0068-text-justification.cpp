class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        int n=words.size();
        for(int i=0;i<n;i++){
            string temp="";
            while(i<n && temp.length()+words[i].length()<=maxWidth){
                temp+=words[i];
                temp+=" ";
                i++;
            }
            temp.pop_back();
            ans.push_back(temp);
            i--;
        }
        vector<string>ans2;
        for(int i=0;i<ans.size()-1;i++){
            istringstream iss(ans[i]);
            string temp;
            vector<string>v;
            int len=0;
            while(iss>>temp){
                v.push_back(temp);
                len+=temp.length();
            }
            string tempSpace="";
            int space=0,extra=0;
            if(v.size()>1){
                  space=((maxWidth-len)/(v.size()-1));
                  extra=((maxWidth-len)%(v.size()-1));
                 while(space) tempSpace+=" ",space--;
            }
            else{
                space=maxWidth-len;
                while(space) tempSpace+=" ",space--;
            }
            for(int j=0;j<v.size()-1;j++){
                v[j]+=tempSpace;
                if(extra>0) v[j]+=" ",extra--;
            }
            if(v.size()==1) v[v.size()-1]+=tempSpace;
            temp="";
            for(auto i:v){
                temp+=i;
            }
            ans2.push_back(temp);
            
        }
        int len=maxWidth-ans[ans.size()-1].length();
        while(len--)ans[ans.size()-1]+=" ";
        ans2.push_back(ans[ans.size()-1]);
        return ans2;
        
    }
};