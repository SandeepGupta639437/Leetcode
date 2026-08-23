class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int cntQueHalf = 0;
        int cntOtherHalf = 0;

        int firstHalfSum = 0;
        int secondHalfSum = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                if (i < n / 2)
                    cntQueHalf++;
                else
                    cntOtherHalf++;
            }
            else {
                if (i < n / 2)
                    firstHalfSum += num[i] - '0';
                else
                    secondHalfSum += num[i] - '0';
            }
        }

        // Odd number of '?' -> Alice always wins
        if ((cntQueHalf + cntOtherHalf) % 2) return true;

        int diff = firstHalfSum - secondHalfSum;
        int qDiff = cntOtherHalf - cntQueHalf;

        return diff != (qDiff / 2) * 9;
    }
};