class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        map<char,int>mp;
        for(char ch:word){
            mp[ch]++;
        }
        vector<pair<char, int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        int cnt = 0;
        int val = 1;

        for(int i=0;i<v.size();i++){
            ans += val*v[i].second;
            cnt++;
            if(cnt%8==0){
                val++;
            }
        }
        return ans;
    }
};