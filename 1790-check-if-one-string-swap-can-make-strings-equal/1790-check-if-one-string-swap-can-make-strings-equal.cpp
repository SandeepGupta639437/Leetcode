class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int first = -1, second = -1, count = 0;
        
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                count++;
                if (count > 2) return false; // More than two mismatches, swapping won't help
                if (first == -1) first = i;
                else second = i;
            }
        }
        
        // If no mismatches, strings are already equal
        if (count == 0) return true;

        // If exactly two mismatches, check if swapping makes them equal
        return (count == 2 && s1[first] == s2[second] && s1[second] == s2[first]);
    }
};
