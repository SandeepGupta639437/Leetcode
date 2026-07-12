class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int startHr = (startTime[0]-'0')*10+(startTime[1]-'0');
        int startMin = (startTime[3]-'0')*10+(startTime[4]-'0');
        int startSec = (startTime[6]-'0')*10+(startTime[7]-'0');
        int endHr = (endTime[0]-'0')*10+(endTime[1]-'0');
        int endMin = (endTime[3]-'0')*10+(endTime[4]-'0');
        int endSec = (endTime[6]-'0')*10+(endTime[7]-'0');
        int ans = 0;
        ans -= startSec;
        ans -= startMin*60;;
        ans -= startHr*60*60;

        ans += endSec;
        ans += endMin*60;
        ans += endHr*60*60;

        return ans;
    }
};