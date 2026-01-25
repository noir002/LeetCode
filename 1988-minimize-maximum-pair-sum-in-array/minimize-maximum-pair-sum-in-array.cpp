class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int maxi = INT_MIN;

        int n = nums.size();

        for(int i = 0; i<n/2; i++){
            int sum = nums[i] + nums[n-i-1];
            maxi = max(maxi ,sum);
        }

        return maxi;
    }
};