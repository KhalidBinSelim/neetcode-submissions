class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {
                res = num;
            }
            if (num == res) {
                cnt++;
            } else {
                cnt--;
            }
        }
        int occurrences = 0;
        for (int num : nums) {
            if (num == res) {
                occurrences++;
            }
        }
        if (occurrences > nums.size() / 2) {
            return res;
        } else {
            return -1;
        }
    }
};