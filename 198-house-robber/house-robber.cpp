class Solution {
public:
    int solution(vector<int>&nums, int n, int i, vector<int> &dp){
        
        if(i >= n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int rob = nums[i] + solution(nums, n, i+2, dp);
        int skipped = solution(nums, n, i+1, dp);

        return dp[i] = max(rob, skipped);

    
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> dp(n+1, -1);

        return solution(nums, n, i, dp);
        

    }
};