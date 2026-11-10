class Solution {
public:
        int climbStairs(int n, vector<int>& costs) {
        int v0 = 0, v1 = 0, v2 = 0, v;
        for (int c : costs) {
            v = min({v0 + 9, v1 + 4, v2 + 1}) + c;
            v0 = v1;
            v1 = v2;
            v2 = v;
        }
        return v2;
    }
};