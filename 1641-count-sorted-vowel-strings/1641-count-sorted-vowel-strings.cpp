class Solution {
public:
    int n;

    int solve(int len, int vowel) {
        if(len == n)  return 1;

        int ans = 0;

        for(int i = vowel; i < 5; i++) {
            ans += solve(len + 1, i);
        }

        return ans;
    }

    int countVowelStrings(int N) {
        n = N;
        return solve(0, 0);
    }
};