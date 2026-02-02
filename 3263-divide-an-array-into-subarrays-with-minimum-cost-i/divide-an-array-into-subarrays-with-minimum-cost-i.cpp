class Solution {
public:
    int minimumCost(vector<int>& nums) {
        if(nums.size() == 3){
            return nums[0] + nums[1]+ nums[2];
        }

        int one = nums[0];
        nums.erase(nums.begin());
        sort(nums.begin(), nums.end());

        
       
        int sum = one + nums[0] +nums[1];
       
        return sum;
    }
};