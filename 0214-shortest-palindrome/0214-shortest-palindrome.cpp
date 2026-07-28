class Solution {
public:
    void computeLPSArray(string& pattern,int M,vector<int>& LPS){
        int len =0;
        LPS[0] =0;

        int i= 1;
        while(i<M){
            if(pattern[i] == pattern[len]){
                len++;
                LPS[i] = len;
                i++;
            }else{
                if(len!=0){
                    len = LPS[len-1];
                }else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string S = s;
        string rev = s;
        reverse(begin(rev),end(rev));
        s = s + "$" + rev;

        int m = s.size();
        vector<int>LPS(m,0);
        int n = rev.size();

        computeLPSArray(s,m,LPS);
        return rev.substr(0,n-LPS[m-1])+S;
    }
};