class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);
        
        // Count the frequency of each character in magazine
        for (char ch : magazine) {
            freq[ch - 'a']++;
        }

        // Check if we have enough characters in magazine to construct ransomNote
        for (char ch : ransomNote) {
            if (freq[ch - 'a'] == 0) {
                return false; // Not enough characters
            }
            freq[ch - 'a']--; // Use one character
        }
        
        return true;
    }
};
