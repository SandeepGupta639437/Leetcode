class Solution {
public:
    string clearDigits(string s) {
        string new1;
        for (char it : s) {
            if (it >= '0' && it <= '9') {
                if (!new1.empty()) new1.pop_back(); // Remove leftmost (last added) character
            } else {
                new1.push_back(it); // Add non-digit characters
            }
        }
        return new1;
    }
};
