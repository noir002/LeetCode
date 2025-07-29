class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> last_seen(32, -1); 

        
        for (int i = n - 1; i >= 0; --i) {
            
            for (int b = 0; b < 32; ++b) {
                if (nums[i] & (1 << b)) {
                    last_seen[b] = i; 
                }
            }

            
            int max_len = i;
            for (int b = 0; b < 32; ++b) {
                if (last_seen[b] != -1) {
                    max_len = max(max_len, last_seen[b]);
                }
            }

            res[i] = max_len - i + 1;
        }

        return res;
    }
};