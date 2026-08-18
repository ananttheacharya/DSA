class Solution {
  int largestInteger(List<int> nums, int k) {
    List<int> cnt = List.filled(51, 0);

    for (int x in nums) {
      cnt[x]++;
    }

    if (k == nums.length) {
      return nums.reduce((a, b) => a > b ? a : b);
    }

    if (k == 1) {
      int ans = -1;

      for (int x in nums) {
        if (cnt[x] == 1 && x > ans) {
          ans = x;
        }
      }

      return ans;
    }

    int a = cnt[nums.first] == 1 ? nums.first : -1;
    int b = cnt[nums.last] == 1 ? nums.last : -1;

    return a > b ? a : b;
  }
}