class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> bll;
        for(auto it: text){
            if(it == 'b' || it == 'a' || it == 'l'||it == 'o'||it == 'n')  bll[it]++;
        }

        int mini = min({bll['b'], bll['a'], bll['l']/2, bll['o']/2, bll['n']});
        

        return mini;

        
    }
};