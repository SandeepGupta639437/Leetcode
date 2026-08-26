class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans= "";

        int l = 0,r = 0;
        int cnt1= 0;
        int prevLen = INT_MAX;
        int n=s.length();
        while(r<n){
            if(s[r] == '1')cnt1++;

            if(cnt1==k){
                while(s[l]=='0')l++;

                int len = r-l+1;
                string temp = s.substr(l, len);

                if(len<prevLen || (len==prevLen && temp<ans)){
                    ans = temp;
                    prevLen = len;
                }
                l++;
                cnt1--;
            }
            
            r++;
        }

        return ans;
    }
};