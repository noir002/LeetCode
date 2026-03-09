class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        

        int n = capacity.size();

        int minCap = 101;
        

        for(int i = 0; i < n; i++){
            if(capacity[i] >= itemSize){
                minCap = min(minCap, capacity[i]);
            }
        }

        if(minCap == 101){
            return -1;
        }

        int idx = find(capacity.begin(), capacity.end(), minCap) - capacity.begin();

        return idx;

        
        

    }
};