class Solution {
public:
    int countValidPrefixes(string s) {
        int cnt = 0,ans = 0;
        for(auto ch:s){
            if(ch=='0')cnt++;
            else cnt--;
            if(cnt<2 && cnt>-2)ans++;
        }
        return ans;
        
    }
};