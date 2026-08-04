class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val mp = HashMap<Int,Int>()
        var i = 1
        for(x in nums){
            if((target - x) in mp)return intArrayOf(mp[target-x]!!-1,i-1)
            mp[x] = i
            i++
        }
        return intArrayOf()
    }
}