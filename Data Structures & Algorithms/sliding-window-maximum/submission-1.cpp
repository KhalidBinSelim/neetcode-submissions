class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> res;
        int l = 0, r = 0;
        while (r < n) {
            while (!dq.empty() and nums[dq.back()] < nums[r]) dq.pop_back();
            dq.push_back(r);
            if (l > dq.front()) dq.pop_front();
            if (r >= k - 1) {
                res.push_back(nums[dq.front()]);
                l++;
            }
            r++;
        }
        return res;
    }
};