use std::collections::HashSet;

impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        if k <= 0 {
            return false;
        }

        let k = k as usize;
        let mut window = HashSet::new();

        for i in 0..nums.len() {
            if window.contains(&nums[i]) {
                return true;
            }

            window.insert(nums[i]);

            if i >= k {
                window.remove(&nums[i - k]);
            }
        }

        false
    }
}