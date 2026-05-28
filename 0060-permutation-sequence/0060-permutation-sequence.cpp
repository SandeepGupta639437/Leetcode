class Solution {
public:

    string ans = "";
    vector<int> elements;

    void solve(int n, int k, int j) {

        if(j == n) {
            return;
        }

        long long fact = factor(n - 1 - j);

        int idx = (k - 1) / fact;

        ans += to_string(elements[idx]);

        elements.erase(elements.begin() + idx);

        k = k - idx * fact;

        solve(n, k, j + 1);
    }

    long long factor(int n) {

        long long facto = 1;

        for(int i = 1; i <= n; i++) {
            facto *= i;
        }

        return facto;
    }

    string getPermutation(int n, int k) {

        for(int i = 1; i <= n; i++) {
            elements.push_back(i);
        }

        solve(n, k, 0);

        return ans;
    }
};