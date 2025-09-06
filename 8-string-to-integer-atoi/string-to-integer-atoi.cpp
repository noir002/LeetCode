class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        int sign=1, flag=0;
        for(auto x:s){
            if(flag==0 && x==' ') continue;
            else if(flag==0 && (x=='+'||x=='-')){
                flag=1;
                sign=(x=='-'?-1:1);
                continue;
            }
            else if('0'<=x && x<='9'){
                flag=1;
                ans=ans*10+(x-'0');
                if(ans*sign>INT_MAX) return INT_MAX;
                else if(ans*sign<INT_MIN) return INT_MIN;
            }
            else break;
        }
        return ans*sign;
    }
};