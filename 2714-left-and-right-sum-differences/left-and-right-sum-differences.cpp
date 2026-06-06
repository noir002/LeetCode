class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums2(nums);
        reverse(nums2.begin(), nums2.end());

        int sumL;
        int prevL = 0;
        int sumR ;
        int prevR = 0;

        for(int i = 1; i<n; i++){
            sumL = nums[i];
            nums[i] = nums[i-1] + prevL;
            prevL = sumL;

            sumR = nums2[i];
            nums2[i] = nums2[i-1] + prevR;
            prevR = sumR;
        }

        nums[0] = 0;
        nums2[0] = 0;

        for(auto it: nums){
            cout << it << " " ;
        }
        reverse(nums2.begin(), nums2.end());
        for(int i = 0; i<n ; i++){
            nums[i] = abs(nums[i] - nums2[i]);
        }

        return nums;
    }
};