class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int ans = 0;
        int under_score = 0;
        int n = s.size();

        for(int i=0;i<n;i++){
             if(s[i]=='L')ans--;
             else if(s[i]=='R')ans++;
             else under_score++;
        }
        return abs(ans)+under_score;
    }
};