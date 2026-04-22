class Solution {
private:
    void counting_sort(vector<int> &v) {
        unordered_map<int, int> freq;
        int mn = *min_element(v.begin(), v.end());
        int mx = *max_element(v.begin(), v.end());
        for (auto x : v) {
            freq[x]++;
        }
        int idx = 0;
        for (int val = mn; val <= mx; val++) {
            while (freq[val] > 0) {
                v[idx++] = val;
                freq[val]--;
            }
        }
    }

public:
    vector<int> sortArray(vector<int> &nums) {
        counting_sort(nums);
        return nums;
    }
};