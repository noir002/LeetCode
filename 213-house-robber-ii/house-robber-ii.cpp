class Solution {
public:
    int solve(vector<int> &nums, int n, int i, vector<int>&dp){
        if(i >= n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        
            int rob = nums[i] + solve(nums, n, i+2, dp);
            int skip = solve(nums, n, i+1, dp);
        

        return  dp[i] = max(rob, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        if(n == 1) return nums[0];

        return max(solve(nums, n-1, 0, dp1), solve(nums, n,1, dp2));
        
    }
};