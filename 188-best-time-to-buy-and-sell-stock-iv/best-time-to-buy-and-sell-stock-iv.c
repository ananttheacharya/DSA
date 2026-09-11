int maxProfit(int k, int* prices, int pricesSize) {
    // If we can make enough transactions, this becomes
    // the unlimited-transactions problem.
    if (k >= pricesSize / 2) {
        int profit = 0;

        for (int i = 1; i < pricesSize; i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }

    int buy[k + 1];
    int sell[k + 1];

    for (int t = 0; t <= k; t++) {
        buy[t] = -prices[0];
        sell[t] = 0;
    }

    for (int i = 1; i < pricesSize; i++) {
        int price = prices[i];

        for (int t = 1; t <= k; t++) {
            buy[t] = (buy[t] > sell[t - 1] - price)
                   ? buy[t]
                   : sell[t - 1] - price;

            sell[t] = (sell[t] > buy[t] + price)
                    ? sell[t]
                    : buy[t] + price;
        }
    }

    return sell[k];
}