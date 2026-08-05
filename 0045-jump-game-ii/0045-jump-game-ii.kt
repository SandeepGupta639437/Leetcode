class Solution {
    
    fun jump(nums: IntArray): Int {
        val n = nums.size
        val dp = IntArray(n) { -1 }

        fun solve(idx: Int): Int {
            if (idx == n - 1) return 0

            if (dp[idx] != -1) return dp[idx]

            var ans = Int.MAX_VALUE

            for (i in idx + 1..minOf(n - 1, idx + nums[idx])) {
                val next = solve(i)
                if (next != Int.MAX_VALUE) {
                    ans = minOf(ans, 1 + next)
                }
            }

            dp[idx] = ans
            return ans
        }

        return solve(0)
    }
}