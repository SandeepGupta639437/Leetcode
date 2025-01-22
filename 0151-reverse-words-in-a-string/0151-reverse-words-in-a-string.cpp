class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());

        int l = 0, j = 0;
        while (j < n) {
            while (j < n && s[j] == ' ') j++;  
            if (j >= n) break;
            if (l > 0) s[l++] = ' ';  
            int start = l;
            while (j < n && s[j] != ' ') s[l++] = s[j++]; 
            reverse(s.begin() + start, s.begin() + l); 
        }
        s.resize(l); 
        return s;
    }
};
