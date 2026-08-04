class Solution {
    fun transformArray(nums: IntArray): IntArray {
        var n = nums.size
        for(i in 0 until n){
            if(nums[i]%2==0){
                nums[i] = 0;
            }else nums[i] = 1;
        }
        nums.sort()
        return nums
    }
}