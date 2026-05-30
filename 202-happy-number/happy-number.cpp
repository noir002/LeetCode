class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> mp;
        vector<int> v;
       
        while(n>0){
            int sum = 0;
            int rem = n%10;
            int sq = rem*rem;
            v.push_back(sq);
            n = n/10;
            
            if(n == 0){
                for(auto it: v){
                    sum += it;
                }
                v.clear();

                if(sum == 1){
                    return true;
                }

                if(mp[sum] == 1){
                    return false;
                }else{
                    mp[sum]++;
                }

                n = sum;
            }
            //cout << "Entering here" ;
        }
        return false;
        
    }
};