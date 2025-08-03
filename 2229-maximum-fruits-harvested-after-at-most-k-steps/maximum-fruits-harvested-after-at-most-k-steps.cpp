class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
         int n = fruits.size();
        int maxFruits = 0;
        int total = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            total += fruits[right][1];

            // Slide the window left while distance is invalid
            while (left <= right && minSteps(fruits[left][0], fruits[right][0], startPos) > k) {
                total -= fruits[left][1];
                ++left;
            }

            maxFruits = max(maxFruits, total);
        }

        return maxFruits;
    }

private:
    int minSteps(int left, int right, int start) {
        // Move left then right OR right then left
        int leftFirst = abs(start - left) + abs(right - left);
        int rightFirst = abs(start - right) + abs(right - left);
        return min(leftFirst, rightFirst);
    }
};