class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.length();
        s += s;
        int ans = 0;
        for(int i=0;i<n;i++){
            int score = 0;
            for(int j=i;j<i+n-1;j++){
                if(s[j]==s[j+1])score++;
            }
            if(score==k)ans++;
        }
        return ans;
    }
};