class Solution {
public:
    bool isLeapYear(int year){
        if(year % 400 == 0) return true;
        if(year % 100 == 0) return false;
        return year % 4 == 0;
    }
    string dayOfTheWeek(int day, int month, int year) {
        int tD = 0;
        for(int y = 1971;y<year;y++){
            tD+=isLeapYear(y)?366:365;
        }
        int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        string days[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        for(int m = 1;m<month;m++){
            tD+=monthDays[m-1];
            if(m==2 && isLeapYear(year))tD+=1;
        }
        tD+=day;
        return days[(tD+4)%7];

    }
};