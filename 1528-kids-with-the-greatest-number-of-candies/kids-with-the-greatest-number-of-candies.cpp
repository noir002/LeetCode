class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<int> copy = candies;
        sort(copy.begin(), copy.end(), greater<int>());
        int high = copy[0];
        vector<bool> ans;

        for(int i = 0; i<candies.size(); i++){
            if(candies[i]+ extraCandies >= high){
                ans.push_back(true);
            }else{
                 ans.push_back(false);
            }

        }

        return ans;

        
    }
};