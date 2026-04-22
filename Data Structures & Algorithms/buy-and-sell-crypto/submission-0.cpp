class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), profit = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prices[j] > prices[i]) profit = max(profit, (prices[j] - prices[i]));
            }
        }
        return profit;
    }
};