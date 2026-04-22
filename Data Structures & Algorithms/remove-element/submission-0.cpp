class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int length_of_nums = nums.size();
        for (int i = 0; i < length_of_nums; i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};