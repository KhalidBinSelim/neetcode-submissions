class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int val: nums) {
            int idx = abs(val) - 1;
            if (nums[idx] < 0) return abs(val);
            nums[idx] *= -1;
        }
        return -1;
    }
};