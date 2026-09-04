class Solution {
public:

    bool allEven(vector<int>& nums1){
        for(int i = 0; i<nums1.size(); i++){
            if(nums1[i]%2 != 0)return false;
        }
        return true;
        
    }


    bool allOdd(vector<int>& nums1){
        for(int i = 0; i<nums1.size(); i++){
            if(nums1[i]%2 == 0)return false;
        }
        return true;
        
    }

    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int> sorted = nums1;
        sort(sorted.begin(), sorted.end());

        int smlOdd;
        int smlEven;
        for(int i = 0; i<n; i++){
            if(sorted[i] % 2 != 0){
                smlOdd = sorted[i];
                break;
            }
        }

         for(int i = 0; i<n; i++){
            if(sorted[i] % 2 == 0){
                smlEven = sorted[i];
                break;
            }
         }
        
        if(allEven(nums1) || allOdd(nums1) || (smlEven > smlOdd) ){
            return true;
        }

        return false;
        
    }
};