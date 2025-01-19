class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> count;
        for (const string& str : arr) {
            count[str]++;
        }
        int distinctCount = 0;
        for (const string& str : arr) {
            if (count[str] == 1) {
                distinctCount++;
                if (distinctCount == k) {
                    return str;
                }
            }
        }
        return ""; 
    }
};
