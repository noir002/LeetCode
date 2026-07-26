class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 3) return nums[0]*nums[1]*nums[2];

        int l1 = nums[0]*nums[1]*nums[2];
        int l2 = nums[n-1]*nums[n-2]*nums[n-3];
        int l3 = nums[0]*nums[1]*nums[n-1];
        int l4 = nums[0]*nums[n-1]*nums[n-2];

        int l5 = max({l1,l2,l3,l4});

        return l5;


    }
};