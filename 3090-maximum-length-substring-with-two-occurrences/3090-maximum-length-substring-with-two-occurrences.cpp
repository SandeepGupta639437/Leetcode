class Solution {
public:
    int maximumLengthSubstring(string s) {
        map<char,int>mp;
        int n = s.length();
        int l = 0, r = 1;
        mp[s[0]]=1;
        int ans = 0;
        while(r<n){
            mp[s[r]]++;
            if(mp[s[r]]>2){
                while(s[l]!=s[r]){
                    mp[s[l]]--;
                    l++;
                }
                mp[s[r]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};