class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        

        int n = capacity.size();

        int minCap = INT_MAX;
        

        for(int i = 0; i < n; i++){
            if(capacity[i] >= itemSize){
                minCap = min(minCap, capacity[i]);
            }
        }

        if(minCap == INT_MAX){
            return -1;
        }

        int idx = find(capacity.begin(), capacity.end(), minCap) - capacity.begin();

        return idx;

        
        

    }
};