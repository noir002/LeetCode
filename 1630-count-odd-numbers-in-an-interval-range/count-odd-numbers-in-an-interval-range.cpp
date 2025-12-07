class Solution {
public:
    int countOdds(int low, int high) {

        int count;
        
        if(low%2 == 0 && high%2 ==0){
            count = (high - low)/2;
        }
        else if((low%2 == 0 && high%2 !=0) || (low%2 != 0 && high%2 ==0)){
            count = ((high - low)/2) + 1;
        }
        else{
            count = ((high - low)/2) + 1;
        }

        return count;
    }
};