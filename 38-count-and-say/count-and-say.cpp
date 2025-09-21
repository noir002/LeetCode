class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";

        string current = "1";
        for (int i = 2; i <= n; i++) {
            string next = "";
            int count = 1;

            for (int j = 0; j < current.size(); j++) {
                if (j + 1 < current.size() && current[j] == current[j + 1])
                    count++;
                else {
                    next += to_string(count) + current[j];
                    count = 1;
                }
            }

            current = next;
        }

        return current;
    }
};