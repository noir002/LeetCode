class Solution {
public:
    int FirstOccuring(vector<int> &nums, int n, int k)
    {
        int low = 0, high = n-1;
        int first = -1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid]==k)
            {
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] < k){
                 low = mid + 1;
            } 
        else{
            high =  mid - 1;
        }
     }
        return first;
    }
    int LastOccuring(vector<int> &nums, int n, int k)
    {
        int low = 0, high = n-1;
        int last = -1;
        while(low <= high)
        {
             int mid = low + (high - low)/2;
            if(nums[mid]==k)
            {
                last = mid;
              low = mid + 1;
            }
            else if(nums[mid] < k) {
                low = mid +1;
            }
            else {
               high = mid - 1;
            }
        }
        return last;
    }
    
    vector<int> searchRange(vector<int>& nums,int k) 
    {
        int n = nums.size();
        int first = FirstOccuring(nums, n, k);
        if(first == -1) return {-1, -1};
        int last = LastOccuring(nums, n, k);
        return {first , last};
        }
};