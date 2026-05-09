class Solution {
public:
    int minFlips(string s) {
        int cnt = 0 ,cnt0=0;
        int n = s.length();
        for(auto i:s){
            if(i=='1')cnt++;
            if(i=='0')cnt0++;
        }
        if(s=="101")return 0;
        if(cnt == 0 || n<3 || cnt0==0)return 0;
        if(s[0] == '1' && s[n-1]=='1')return min(cnt-2,cnt0);
        return min(cnt-1,cnt0);
    }
};