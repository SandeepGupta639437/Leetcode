class Solution {
public:
    int minimumFlips(int n) {
        string s = bitset<32>(n).to_string();
        s.erase(0, min(s.find('1'), s.size()-1));
        string s_ = s;
        reverse(begin(s),end(s));
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=s_[i])ans++;
        }
        return ans;
    }
};