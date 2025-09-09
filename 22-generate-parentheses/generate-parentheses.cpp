class Solution {
public:
    void helper(vector<string> &ans, string gg, int o, int c, int n){
        if(o == c && c+o == n*2){
            ans.push_back(gg);
            return;
        }
        if(o < n){
            helper(ans, gg + "(", o + 1, c, n);
        }
        if(c < o){
            helper(ans, gg + ")", o, c + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, "", 0, 0, n);
        return ans;
    }
};