object Solution {
    def largestInteger(nums: Array[Int], k: Int): Int = {
        val cnt = Array.fill(51)(0)

        nums.foreach(x => cnt(x) += 1)

        if (k == nums.length) {
            return nums.max
        }

        if (k == 1) {
            var ans = -1

            nums.foreach { x =>
                if (cnt(x) == 1) {
                    ans = math.max(ans, x)
                }
            }

            return ans
        }

        val a = if (cnt(nums.head) == 1) nums.head else -1
        val b = if (cnt(nums.last) == 1) nums.last else -1

        math.max(a, b)
    }
}