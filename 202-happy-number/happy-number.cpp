class Solution {
public:
    bool isHappy(int n) {
        unordered_set< int> check;
        while(n != 1 && !check.count(n)){
            check.insert(n);
            n = square(n);
        }

        return n == 1;


    }
private: 
    int square(int n){
        int sum = 0;

        while(n>0){
            
            int x = n%10;
            sum = sum+ (x*x);
            n = n/10;

        }
        return sum;

    }
};