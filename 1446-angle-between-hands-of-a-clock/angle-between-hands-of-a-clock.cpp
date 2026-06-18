class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = abs(minutes -  (hour*5 + (minutes* 0.083333333))) * 6;
        double ans2 = 360 - ans;
        return min(ans,ans2);
    }
};