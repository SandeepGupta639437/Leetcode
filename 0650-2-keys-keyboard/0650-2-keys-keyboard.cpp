class Solution {
private:
    int targetLength;
    int dp[1001][1001];

    int findMinSteps(int currentLength, int clipboardLength) {
        if (currentLength == targetLength) return 0;
        if (currentLength > targetLength) return INT_MAX / 2;
        if(dp[currentLength][clipboardLength]!=-1)return dp[currentLength][clipboardLength];

        int copyAndPaste = 2 + findMinSteps(currentLength * 2, currentLength);
        int pasteOnly = 1 + findMinSteps(currentLength + clipboardLength, clipboardLength);

        return dp[currentLength][clipboardLength] = min(copyAndPaste, pasteOnly);
    }

public:
    int minSteps(int n) {
        if (n == 1) return 0;
        targetLength = n;
        memset(dp,-1,sizeof(dp));
        return 1 + findMinSteps(1, 1);
    }
};