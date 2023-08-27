class Solution {
public:
    map<pair<int,int>,bool>m;
    bool help(int i,int prev,vector<int>&stones){
        if(i>stones.size()) return false;
        if(i==(stones.size()-1)) return true;
        if(m.find({i,prev})!=m.end()) return m[{i,prev}];
        int op1=false;
        int j1=prev+1+stones[i],j2=prev-1+stones[i],j3=prev+stones[i];
        auto it=lower_bound(stones.begin(),stones.end(),j1)-stones.begin();
        auto it2=lower_bound(stones.begin(),stones.end(),j2)-stones.begin();
        auto it3=lower_bound(stones.begin(),stones.end(),j3)-stones.begin();
        if(it<stones.size()&& it>i &&  stones[it]==j1) op1|=help(it,prev+1,stones);
        if(it2<stones.size() && it2>i && stones[it2]==j2) op1|=help(it2,prev-1,stones);
        if(it3<stones.size() && it3>i && stones[it3]==j3) op1|=help(it3,prev,stones);
        return m[{i,prev}]=op1;
    }
    bool canCross(vector<int>& stones) {
        return help(0,0,stones);
    }
};