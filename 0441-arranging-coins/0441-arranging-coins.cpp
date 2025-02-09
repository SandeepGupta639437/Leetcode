class Solution {
public:
    int arrangeCoins(int n) {
        long long sum = 0; // Start from 0
        int i = 0;
        
        while (sum + i + 1 <= n) { // Check if the next row can be formed
            i++;
            sum += i; // Add i to the sum
        }
        
        return i; // Return the last valid row count
    }
};
