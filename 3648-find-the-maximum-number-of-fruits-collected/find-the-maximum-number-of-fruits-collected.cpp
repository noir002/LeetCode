class Solution {
    int n;
    vector<vector<int>> t;

public:

    // \U0001f466 Child 1 collects from the main diagonal
    int child1Collect(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += grid[i][i];
            grid[i][i] = 0; // ⚠️ Prevent reuse by other children
            t[i][i] = 0;    // Invalidate memo table on diagonal
        }
        return ans;
    }

    // \U0001f466 Child 2: Starts at top-right, moves diagonally left/down
    int child2Collect(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= n) return 0;
        if (i == n - 1 && j == n - 1) return 0;
        if (i >= j) return 0; // Can't go to or below the diagonal

        if (t[i][j] != -1) return t[i][j];

        int leftcorner = grid[i][j] + child2Collect(i + 1, j - 1, grid);
        int middle     = grid[i][j] + child2Collect(i + 1, j, grid);
        int rightcorner= grid[i][j] + child2Collect(i + 1, j + 1, grid);

        return t[i][j] = max({leftcorner, middle, rightcorner});
    }

    // \U0001f466 Child 3: Starts at bottom-left, moves diagonally right/up
    int child3Collect(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= n) return 0;
        if (i == n - 1 && j == n - 1) return 0;
        if (j >= i) return 0; // Can't go to or above the diagonal

        if (t[i][j] != -1) return t[i][j];

        int topcorner   = grid[i][j] + child3Collect(i - 1, j + 1, grid);
        int right       = grid[i][j] + child3Collect(i, j + 1, grid);
        int rightcorner = grid[i][j] + child3Collect(i + 1, j + 1, grid);

        return t[i][j] = max({topcorner, right, rightcorner});
    }

    int maxCollectedFruits(vector<vector<int>>& grid) {
        n = grid.size();
        t.resize(n, vector<int>(n, -1)); // \U0001f9e0 DP table

        int firstChildScore  = child1Collect(grid);           // \U0001f466 Child 1
        int secondChildScore = child2Collect(0, n - 1, grid); // \U0001f466 Child 2
        int thirdChildScore  = child3Collect(n - 1, 0, grid); // \U0001f466 Child 3

        return firstChildScore + secondChildScore + thirdChildScore;
    }    
};