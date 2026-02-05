class Solution {
public:
    unordered_map<string, int> mpp;

    bool hasDuplicate(string s1, string s2) {
        int arr[26] = {0};

        for (char ch : s1) {
            if (arr[ch - 'a'] > 0) return true;
            arr[ch - 'a']++;
        }

        for (char ch : s2) {
            if (arr[ch - 'a'] > 0) return true;
        }

        return false;
    }

    int solve(string temp, vector<string>& arr, int idx, int n) {
        if (idx >= n) {
            return temp.length();
        }

        string key = temp + "#" + to_string(idx);
        if (mpp.find(key) != mpp.end()) {
            return mpp[key];
        }

        int exclude = solve(temp, arr, idx + 1, n);
        int include = 0;

        if (!hasDuplicate(arr[idx], temp)) {
            include = solve(temp + arr[idx], arr, idx + 1, n);
        }

        return mpp[key] = max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        mpp.clear();
        int n = arr.size();
        return solve("", arr, 0, n);
    }
};
