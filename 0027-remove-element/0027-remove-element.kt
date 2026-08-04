class Solution {
    fun removeElement(nums: IntArray, `val`: Int): Int {
        var count = 0
        val n = nums.size
        for (i in 0 until n) {
            if (nums[i] != `val`) {
                nums[count] = nums[i]
                count++
            }
        }
        return count
    }
}