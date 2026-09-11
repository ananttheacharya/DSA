impl Solution {
    pub fn max_profit(k: i32, prices: Vec<i32>) -> i32 {
        let n = prices.len();
        let k = k as usize;

        // Unlimited transactions case
        if k >= n / 2 {
            let mut profit = 0;

            for i in 1..n {
                if prices[i] > prices[i - 1] {
                    profit += prices[i] - prices[i - 1];
                }
            }

            return profit;
        }

        let mut buy = vec![0; k + 1];
        let mut sell = vec![0; k + 1];

        for t in 1..=k {
            buy[t] = -prices[0];
        }

        for i in 1..n {
            let price = prices[i];

            for t in 1..=k {
                buy[t] = buy[t].max(sell[t - 1] - price);
                sell[t] = sell[t].max(buy[t] + price);
            }
        }

        sell[k]
    }
}