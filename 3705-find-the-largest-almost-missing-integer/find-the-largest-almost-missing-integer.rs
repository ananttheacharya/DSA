impl Solution {
    pub fn largest_integer(nums: Vec<i32>, k: i32) -> i32 {
        let mut cnt = vec![0; 51];

        for &x in &nums {
            cnt[x as usize] += 1;
        }

        if k as usize == nums.len() {
            return *nums.iter().max().unwrap();
        }

        if k == 1 {
            let mut ans = -1;

            for &x in &nums {
                if cnt[x as usize] == 1 {
                    ans = ans.max(x);
                }
            }

            return ans;
        }

        let a = if cnt[nums[0] as usize] == 1 {
            nums[0]
        } else {
            -1
        };

        let b = if cnt[nums[nums.len() - 1] as usize] == 1 {
            nums[nums.len() - 1]
        } else {
            -1
        };

        a.max(b)
    }
}