class Solution {
public:
    int lb(vector<int>&nums, int target){
        int n = nums.size();
        int l = 0;
        int r = n -1;
        int ans = n;
        while(l<=r){
            int mid = l +(r-l)/2;
            if(target <= nums[mid]){
                ans = mid;
                r = mid -1;
            }
            else{
                l = mid +1;
            }

        }

        return ans;
    }

int ub(vector<int>&nums, int target){
        int n = nums.size();
        int l = 0;
        int r = n -1;
        int ans = n;
        while(l<=r){
            int mid = l +(r-l)/2;
            if(target < nums[mid]){
                ans = mid;
                r = mid -1;
            }
            else{
                l = mid +1;
            }

        }

        return ans;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lbound = lb(nums,target);
        int ubound = ub(nums,target);

        if(lbound == ubound){
            return {-1,-1};

        }
        else{
            return {lbound,ubound-1};
        }




        
    }
};