class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1, el2, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt1 == 0 and nums[i] != el2) {
                el1 = nums[i];
                cnt1++;
            } else if (cnt2 == 0 and nums[i] != el1) {
                el2 = nums[i];
                cnt2++;
            }
            else if (nums[i] == el1) {
                cnt1++;
            } else if (nums[i] == el2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1 = 0, cnt2 = 0;
        for (int val: nums) {
            if (val == el1) {
                cnt1++;
            } else if (val == el2) {
                cnt2++;
            }
        }
        if (cnt1 > (nums.size() / 3)) {
            ans.push_back(el1);
        }
        if (cnt2 > (nums.size() / 3)) {
            ans.push_back(el2);
        }
        sort(ans.begin(), ans.end()); 
        // only 2 elements at max will be present in ans, so 2log2 = 2 = O(1) appx. even after sorting.
        return ans;
    }
};