class Solution {
public:
    string toBinary(int v) {
        if (v == 0) return "0";
        string bin;
        while (v) {
            bin.push_back((v & 1) + '0');
            v >>= 1;
        }
        reverse(bin.begin(), bin.end());
        return bin;
    }
    int minimumFlips(int n) {
        string s = toBinary(n);
        string s_ = s;
        reverse(begin(s),end(s));
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=s_[i])ans++;
        }
        return ans;
    }
};