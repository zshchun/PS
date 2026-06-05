impl Solution {
    pub fn max_ascending_sum(nums: Vec<i32>) -> i32 {
        let sz = nums.len();
        let mut max = 0;
        let mut sum = 0;
        for i in 0..sz {
            if i == 0 || nums[i - 1] < nums[i] {
                sum += nums[i];
            } else {
                sum = nums[i];
            }
            max = max.max(sum);
        }
        max
    }
}
