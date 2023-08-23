class Solution
{
public:
    string reorganizeString(string s)
    {
        int n=s.size();
        map<char, int> m;
        int maxi=0,maxiChar='@';
        for (auto i : s)
        {
            m[i]++;
            if(m[i]>ceil(n/2.0)){
                return "";
            }
            if(maxi<m[i]){
                maxiChar=i;
                maxi=m[i];
            }
        }
        int i = 0, k = 1;
        int c=m[maxiChar];
         while (c)
            {
                if (i < s.length())
                {
                    s[i] =maxiChar;
                    i+=2;
                }
                else if(k<s.length()){
                    s[k] = maxiChar;
                    k+=2;
                }
                 c--;
            }
        m[maxiChar]=0;
        for (auto j : m)
        {
            int count=j.second;
            while (count)
            {
                if (i < s.length())
                {
                    s[i] = j.first;
                    i+=2;
                }
                else if(k<s.length()){
                    s[k] = j.first;
                    k+=2;
                }
                 count--;
            }
        }
        return s;
    }
};