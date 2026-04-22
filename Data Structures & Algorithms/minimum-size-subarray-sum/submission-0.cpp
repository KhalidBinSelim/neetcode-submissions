class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), res = INT_MAX;
        for (int i = 0; i < n; i++) {
            long long curSum = 0;
            int j = i;
            while (j < n) {
                curSum += nums[j];
                if (curSum >= target) {
                    res = min(res, j - i + 1);
                    break;
                }
                j++;
            }
        }
        return res == INT_MAX? 0 : res;
    }
};