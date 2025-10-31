class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> hsx(n);
        for(int i = 0; i< nums.size(); i++){
            hsx[nums[i]]++; 
        }

        for(auto it : hsx){
            cout << it << " ";
        }

        vector<int> v;
        for(int i = 0; i<n; i++){
            if(hsx[i]>1){
                v.push_back(i);
            }
        }

        return v;

        
    }
};