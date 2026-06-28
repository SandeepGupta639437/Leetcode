class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                                                int freeStart, int freeEnd) {

        if (occupiedIntervals.empty()) return {};

        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        // Step 1: Merge intervals
        vector<vector<int>> merged;
        for (auto &it : occupiedIntervals) {
            if (merged.empty() || merged.back()[1] < it[0] - 1) {
                merged.push_back(it);
            } else {
                merged.back()[1] = max(merged.back()[1], it[1]);
            }
        }

        // Step 2: Remove [freeStart, freeEnd]
        vector<vector<int>> ans;

        for (auto &it : merged) {
            int l = it[0], r = it[1];

            // Completely outside
            if (r < freeStart || l > freeEnd) {
                ans.push_back({l, r});
            }
            // Completely inside
            else if (l >= freeStart && r <= freeEnd) {
                continue;
            }
            // Covers free interval
            else if (l < freeStart && r > freeEnd) {
                ans.push_back({l, freeStart - 1});
                ans.push_back({freeEnd + 1, r});
            }
            // Left overlap
            else if (l < freeStart) {
                ans.push_back({l, freeStart - 1});
            }
            // Right overlap
            else {
                ans.push_back({freeEnd + 1, r});
            }
        }

        return ans;
    }
};