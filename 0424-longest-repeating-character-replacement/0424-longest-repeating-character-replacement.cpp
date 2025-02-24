class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, ans = 0, n = s.size();
        int mp[26] = {0}; // Frequency array for character counts

        for (int j = 0; j < n; j++) {
            mp[s[j] - 'A']++;  // Increment frequency of the current character

            // Get the maximum occurring character in the window
            int maxFreq = *max_element(mp, mp + 26);

            // \U0001f6d1 If window is invalid (more than `k` replacements needed), shrink it
            while ((j - i + 1) - maxFreq > k) {
                mp[s[i] - 'A']--;  // Remove leftmost character from window
                i++;  // Move left pointer forward
            }

            // ✅ Update the maximum valid window size found so far
            ans = max(ans, j - i + 1);
        }

        return ans; // \U0001f3af Return the longest valid substring length
    }
};