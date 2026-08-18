class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        cnt = [0] * 51

        for x in nums:
            cnt[x] += 1

        if k == len(nums):
            return max(nums)

        if k == 1:
            ans = -1

            for x in nums:
                if cnt[x] == 1:
                    ans = max(ans, x)

            return ans

        a = nums[0] if cnt[nums[0]] == 1 else -1
        b = nums[-1] if cnt[nums[-1]] == 1 else -1

        return max(a, b)