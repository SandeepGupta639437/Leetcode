class Solution {
    fun remainingMethods( n: Int, k: Int, invocations: Array<IntArray> ): List<Int> {

        val graph = Array(n) { mutableListOf<Int>() }

        for (edge in invocations) {
            graph[edge[0]].add(edge[1])
        }

        val suspicious = BooleanArray(n)

        fun dfs(node: Int) {
            suspicious[node] = true
            for (next in graph[node]) {
                if (!suspicious[next]) {
                    dfs(next)
                }
            }
        }

        dfs(k)

        // If an outside method invokes a suspicious method,
        // nothing can be removed.
        for (edge in invocations) {
            val u = edge[0]
            val v = edge[1]

            if (!suspicious[u] && suspicious[v]) {
                val ans = mutableListOf<Int>()
                for (i in 0 until n) ans.add(i)
                return ans
            }
        }

        val ans = mutableListOf<Int>()

        for (i in 0 until n) {
            if (!suspicious[i]) {
                ans.add(i)
            }
        }

        return ans
    }
}