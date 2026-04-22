class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int &val: nums) {
            if (val < 0) {
                val = 0;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            int value = abs(nums[i]);
            if (value >= 1 and value <= nums.size()) {
                int index = abs(nums[i]) - 1;
                if (nums[index] == 0) {
                    nums[index] = - (nums.size() + 1);
                } else if (nums[index] > 0) {  
                    nums[index] *= -1;
                }
            }
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (nums[i - 1] < 0) {
                continue;
            }
            return i;
        }
        return nums.size() + 1;
    }
};