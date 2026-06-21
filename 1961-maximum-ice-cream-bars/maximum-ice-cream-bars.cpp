class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxC = *max_element(costs.begin(), costs.end());
        int sum = 0;
        vector<int> freq(maxC+1, 0);

        for(auto it: costs){
            freq[it]++;
        }

        for(int i = 1; i<=maxC; i++){
            if(freq[i] == 0){
                continue;
            }

            if(i > coins){
                break;
            }

            int buy = min(freq[i], coins/i);
            sum += buy;
            coins -= buy * i;
        }

        return sum;

        
    }
};