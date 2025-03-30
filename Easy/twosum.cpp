class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec1;
        for(int i = 0; i <nums.size()  ; i++ ){
            bool check = false;
            for(int j = i+1; j<nums.size(); j++){
                if((nums[i]+nums[j]) == target){
                    vec1.push_back(i);
                    vec1.push_back(j);
                    check = true;
                    break;
                }
            }
            if(check){
                    break;
                }
        }
        return vec1;
        }
};