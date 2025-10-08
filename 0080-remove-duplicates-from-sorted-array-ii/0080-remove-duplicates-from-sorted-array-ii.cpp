class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int index = 2; // start placing from the 3rd position
        for (int i = 2; i < n; i++) {
            // if current element is not the same as element at index-2, keep it
            if (nums[i] != nums[index - 2]) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};
