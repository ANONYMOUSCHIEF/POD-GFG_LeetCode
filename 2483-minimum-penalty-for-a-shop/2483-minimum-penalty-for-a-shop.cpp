class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int>visit;
        vector<int>notVisit;
        int j=0;
        for(auto i:customers){
            if(i=='Y') visit.push_back(j);
            else notVisit.push_back(j);
            j++;
        }
        int mini=INT_MAX,ans=0;
        while(j>=0){
            int val1=lower_bound(visit.begin(),visit.end(),j)-visit.begin();
            val1=visit.size()-val1+1;
            int val2=lower_bound(notVisit.begin(),notVisit.end(),j)-notVisit.begin()+1;
            
            if((val1+val2)<=mini){
                mini=val1+val2;
                ans=j;
            }
            j--;
        }
        return ans;
    }
};