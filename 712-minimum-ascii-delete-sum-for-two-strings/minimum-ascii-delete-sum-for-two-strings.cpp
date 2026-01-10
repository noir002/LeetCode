class Solution {
public:
    int dp[1001][1001];
    int solve(int idx1, int idx2, string &s1, string &s2) {
        if(idx1 >= s1.length() || idx2 >= s2.length()) return 0;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        int case1 = solve(idx1+1, idx2, s1, s2);
        int case2 = solve(idx1, idx2+1, s1, s2);
        int case3 = solve(idx1+1, idx2+1, s1, s2);
        int ans = max({case1, case2, case3});

        if(s1[idx1] == s2[idx2]) {
            return dp[idx1][idx2] = max(ans, s1[idx1] + s2[idx2] + solve(idx1+1,idx2+1, s1, s2));
        }

        return dp[idx1][idx2] = ans;
    }

    int minimumDeleteSum(string s1, string s2) {
        int totalAsciiValue = 0;

        for(auto ch : s1) totalAsciiValue += ch;
        for(auto ch : s2) totalAsciiValue += ch;

        memset(dp,-1,sizeof(dp));

        return totalAsciiValue - solve(0,0,s1,s2);   
    }
};