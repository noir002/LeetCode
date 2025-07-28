class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1) return true;
        if(n % 2 != 0) return false;
        while(n>2 && n%2 == 0){
            n = n/2;
            if(n % 2 != 0){
                return false;
            }
            
        }
        if(n == 1 || n == 2){
                return true;
            }
        return 0;
    }
};