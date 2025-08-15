class Solution {
public:
    bool check(int n){
        if(n == 1) return true;
        if(n%4 == 0){
            return check(n/4);
        }

        return false;
    }
    bool isPowerOfFour(int n) {
        if(n == 0)return false;
        return check(n);
        
    }
};