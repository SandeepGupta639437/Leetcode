class Solution {
public:

    pair<int,int> getRange( string &s, vector<pair<int,int>> &pos, int c ) {
        int l = pos[c].first;
        int r = pos[c].second;

        for (int i = l; i <= r; i++) {
            int x = s[i] - 'a';

            if (pos[x].first < l) return {-1, -1};

            r = max(r, pos[x].second);
        }

        return {l, r};
    }

    vector<string> maxNumOfSubstrings(string s) {

        vector<pair<int,int>> pos(26, {-1, -1});

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';

            if (pos[idx].first == -1)
                pos[idx].first = i;

            pos[idx].second = i;
        }

        vector<pair<int,int>> ranges;

        for (int c = 0; c < 26; c++) {

            if (pos[c].first == -1)
                continue;

            auto [l, r] = getRange(s, pos, c);

            if (l != -1)
                ranges.push_back({l, r});
        }

        sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) { return a.second < b.second; });

        vector<string> ans;

        int last = -1;

        for (auto &[l, r] : ranges) {

            if (l > last) {
                ans.push_back(s.substr(l, r - l + 1));
                last = r;
            }
        }

        return ans;
    }
};