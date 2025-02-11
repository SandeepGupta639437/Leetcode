#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> premul(n, 1);
        vector<int> postmul(n, 1);

        // Compute prefix products
        for (int i = 1; i < n; i++) {
            premul[i] = premul[i - 1] * nums[i - 1];
        }

        // Compute suffix products
        for (int i = n - 2; i >= 0; i--) {
            postmul[i] = postmul[i + 1] * nums[i + 1];
        }

        // Compute the final result
        for (int i = 0; i < n; i++) {
            nums[i] = premul[i] * postmul[i];
        }

        return nums;
    }
};
