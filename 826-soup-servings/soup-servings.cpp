class Solution {
public:
    double soupServings(int n) {
        if (n == 0) return 0.5;                // both empty at start
        // Scale to 25 mL units
        int N = (n + 24) / 25;
        // Heuristic: for large N the answer is ~1.0 within required tolerance.
        if (N >= 200) return 1.0;             // commonly used threshold (200*25 = 5000 mL; safe to use 4800 too)

        vector<vector<double>> memo(N + 1, vector<double>(N + 1, -1.0));
        function<double(int,int)> dfs = [&](int a, int b) -> double {
            if (a <= 0 && b <= 0) return 0.5;  // both emptied the same turn
            if (a <= 0) return 1.0;            // A emptied first
            if (b <= 0) return 0.0;            // B emptied first
            if (memo[a][b] >= -0.5) return memo[a][b];

            double res = 0.0;
            // four equally likely operations in units of 25 mL:
            res += 0.25 * dfs(max(0, a - 4), b);       // (100, 0)
            res += 0.25 * dfs(max(0, a - 3), max(0, b - 1)); // (75, 25)
            res += 0.25 * dfs(max(0, a - 2), max(0, b - 2)); // (50, 50)
            res += 0.25 * dfs(max(0, a - 1), max(0, b - 3)); // (25, 75)

            memo[a][b] = res;
            return res;
        };

        return dfs(N, N);
    }
};
