class Solution {
private:
    int n;
    int expand(const string& s , int left , int right){
        const int n = s.length();
        while(left >= 0 && right < n && s[left] == s[right]){
            --left; ++right;
        }
        return right - left - 1;
    }
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for(int i = 0, n = s.length(); i < n; ++i){
            int odd = expand(s , i , i);
            int even = expand(s , i , i + 1);
            int maxi = max(odd , even);
            if(maxi > end - start){
                start = i - (maxi - 1) / 2;
                end = i + maxi / 2;
            }
        }
        return s.substr(start , end - start + 1);
    }
};