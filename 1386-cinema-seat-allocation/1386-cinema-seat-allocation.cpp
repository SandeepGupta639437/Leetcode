class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, set<int>> mp;

        for(auto &v : reservedSeats) {
            mp[v[0]].insert(v[1]);
        }

        long long ans = 2LL * (n - mp.size());

        for(auto &[row, seats] : mp) {
            bool x = true; // 2,3,4,5
            bool y = true; // 4,5,6,7
            bool z = true; // 6,7,8,9

            for(int seat : seats) {
                if(seat >= 2 && seat <= 5)
                    x = false;

                if(seat >= 4 && seat <= 7)
                    y = false;

                if(seat >= 6 && seat <= 9)
                    z = false;
            }

            if(x && z)
                ans += 2;
            else if(x || y || z)
                ans++;
        }

        return ans;
    }
};