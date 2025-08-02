class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> count;
        for (int x : basket1) count[x]++;
        for (int x : basket2) count[x]--;

        vector<int> extra;
        for (auto& [val, freq] : count) {
            if (freq % 2 != 0) return -1;
            for (int i = 0; i < abs(freq) / 2; ++i)
                extra.push_back(val);
        }

        sort(extra.begin(), extra.end());
        int n = extra.size();
        int min_val = *min_element(basket1.begin(), basket1.end());
        min_val = min(min_val, *min_element(basket2.begin(), basket2.end()));

        long long cost = 0;
        for (int i = 0; i < n / 2; ++i)
            cost += min(extra[i], 2 * min_val);

        return cost;
    }
};