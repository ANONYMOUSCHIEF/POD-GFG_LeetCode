class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0) return false;
        int pow_of_2=__builtin_popcount(n);
        if(pow_of_2!=1) return false;
        pow_of_2=log2l(n);
        if(pow_of_2 & 1) return false;
        return true;
    }
};