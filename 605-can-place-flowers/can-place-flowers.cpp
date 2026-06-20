class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();
        int sum = 0;
        if(n == 0){
            return true;
        }

        if(s == 1){
            if(flowerbed[0] == 0 && n == 1){
                return true;
            }
            return false;
        }
        if(s == 2){
            if(flowerbed[0] == 0 && flowerbed[1] == 0 && n == 1){
                return true;
            }
            return false;
        }

        for(int i = 1; i < flowerbed.size()-1; i++){
            if(flowerbed[0] == 0 ){
                if(flowerbed[1] == 0){
                    flowerbed[0] = 1;
                    sum++;
                   
                    
                }
            }
            if(flowerbed[s-1] == 0 && flowerbed[s-2] == 0){
                flowerbed[s-1] = 1;
                sum++;
                
            }

            if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0 && flowerbed[i] == 0){
                flowerbed[i] = 1;
                sum++;

            }
        }
        cout << sum << " ";

        for(auto it: flowerbed){
            cout << it << " ";
        }

     

        if(sum>=n){
            return true;
        }

        return false;
        
    }
};