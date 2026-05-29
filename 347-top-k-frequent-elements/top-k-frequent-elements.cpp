class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<pair<int, int>> v;
        for(auto it: mp){
            v.push_back({it.second, it.first});
        }

        sort(v.rbegin(), v.rend());
        vector<int> ans;
        for(int i = 0; i< k; i++){
            ans.push_back(v[i].second);
        }  

        return ans; 

    }
};