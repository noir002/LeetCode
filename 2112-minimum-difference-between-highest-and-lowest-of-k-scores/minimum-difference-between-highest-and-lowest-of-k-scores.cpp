class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        if(nums.size() == 1){
            return 0;
        }

        sort(nums.begin(), nums.end());

        //for(auto it: nums){
        //    cout << it << " ";
        //}

        int n = nums.size();

        int mini = INT_MAX;

        for(int i = 0; i<= n-k ;i++){
            int diff = nums[i+k-1] - nums[i];
            mini = min(mini,diff);
        }
        //int diff = nums[n-1] - nums[n-k] ;
        

        return mini;
    }
};