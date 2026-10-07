class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int curr = 0;
        for(auto &it:s){
            int maxi = max(it-'0',curr);
            int mini = min(it-'0',curr);
            ans += min((maxi-mini),(mini+10-maxi));
            curr = it-'0';
        }
        return ans;
    }
};