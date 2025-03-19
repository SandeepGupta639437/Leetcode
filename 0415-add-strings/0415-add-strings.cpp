class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;

        // Perform digit-by-digit addition from right to left
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            
            // Append the last digit of sum to result
            result.push_back((sum % 10) + '0');
            carry = sum / 10; // Update carry
        }

        // Reverse the string since we added digits from right to left
        reverse(result.begin(), result.end());
        return result;
    }
};
