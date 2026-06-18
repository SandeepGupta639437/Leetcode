class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle = 0;
        double hrAg = hour * 30;
        double minAg = minutes*6;
        hrAg += minutes/2.0;\
        return min(abs(minAg-hrAg),360-abs(minAg-hrAg));
    }
};