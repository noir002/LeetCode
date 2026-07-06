class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 1;
        int high = nums[n-1];
        int ans = 0;
       

        while(high >= low){
            int sum = 0;
            int mid = (high + low)/2;



            for(int i = 0; i< nums.size(); i++){
                sum += ceil((double)nums[i]/mid);
            }

            if(sum > threshold){
                low = mid + 1;
            }else{
                ans = mid;
                high = mid -1;
            }
        }

        return ans;
    }

};