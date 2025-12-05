class Solution {
public:
    int countPartitions(vector<int>& nums) {

        int sum1 = 0;
        int count = 0;
        for(int i = 1; i<nums.size(); i++){
            sum1 = sum1 + nums[i-1];
            //cout << sum1 << endl;
            int sum2 = 0;
            for(int j = i; j<nums.size(); j++){
                sum2 += nums[j];
            }
            //cout << sum2 << endl;

            if((sum1 - sum2)%2 == 0){
                count++;
            }
        }

        return count;
    }
};