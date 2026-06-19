class Solution {
public:
    int largestAltitude(vector<int>& gain) {
      
        gain.insert(gain.begin(), 0);
        int n = gain.size();
        int high = 0;
        for(int i = 1; i<n; i++){
            gain[i] += gain[i-1];
            high = max(high, gain[i]);
        }

        return high;
    }
};