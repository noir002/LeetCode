class Solution {
public:
    int numSteps(string& s) {
        bitset<501> x(s);
        int n=s.size(), cnt=0;
        if (n==1) return 0;
        while (n>1){
            if (x[0]==0){
                x>>=1;
                n--;
            }
            else{
                int i=0;
                for( ; i<n && x[i]==1; i++)
                    x[i]=0;
                if (i<n) x[i]=1;
                else n++;
            }
            cnt++;
        }
        return cnt;
    }
};