class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), profit = 0;
        if (n == 1) return 0;
        int l = 0, r = l + 1;
        while (r < n) {
            if (prices[l] <= prices[r]) {
                profit = max(profit, prices[r] - prices[l]);
                r++;
            } else {
                l++;
                r = l + 1;
            }
        }
        return profit;
    }
};