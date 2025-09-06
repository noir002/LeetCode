class Solution {
public:
    int reverse(int x) {
        int temp = x;
        long long int sum = 0;
        while(temp){
            int digit = temp % 10;
            sum = sum * 10 + digit;
            temp/=10;
        }
        if(sum>INT_MAX || sum<INT_MIN) return 0;
        return sum;
    }
};