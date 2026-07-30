class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int val = 1,cnt = 0;
        for (char ch : word) {
            ans +=val;
            cnt++;
            if(cnt%8==0){
                val++;
            }
        }
        return ans;
    }
};