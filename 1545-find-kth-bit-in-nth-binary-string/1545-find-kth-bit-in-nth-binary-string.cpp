class Solution {
public:
    string invert(string s){
        for(char &c : s) {
                c = (c == '0') ? '1' : '0';
        }
        return s;
    } 
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=2;i<=n;i++){
            string t = invert(s);
            reverse(t.begin(),t.end());
            s=s+"1"+t;
        }
        return s[k-1];
    }
};