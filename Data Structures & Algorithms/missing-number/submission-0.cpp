class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int reqSum = n * (n + 1) / 2;
        int givenSum = 0;
        for (int num: nums) givenSum += num;
        return reqSum - givenSum;
    }
};