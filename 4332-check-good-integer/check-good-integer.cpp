class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum = 0; 
        int psum = 0;
        while(n>0){
            int rem;
            rem = n%10;
            sum += rem;
            psum += (rem*rem);
            n /= 10;
        }

        if(psum - sum < 50){
            return false;
        }

        return true;
        
        
    }
};