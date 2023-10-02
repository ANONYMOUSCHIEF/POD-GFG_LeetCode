class Solution {
public:
    bool winnerOfGame(string s) {
        int alice=0,bob=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='A'){
                int count=0;
                while(i<n && s[i]=='A'){
                    count++;
                    i++;
                }
                if(count>=3) alice+=count-2;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]=='B'){
                int count=0;
                while(i<n && s[i]=='B'){
                    count++;
                    i++;
                }
                if(count>=3) bob+=count-2;
            }
        }
        
        return alice>bob;
    }
};