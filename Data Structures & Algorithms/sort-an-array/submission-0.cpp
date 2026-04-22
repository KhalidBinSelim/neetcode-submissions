class Solution {
private: 
    void merge(vector<int> &v, int l, int mid, int r) {
        vector<int> cur;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (v[i] <= v[j]) {
                cur.push_back(v[i++]);
            } else {
                cur.push_back(v[j++]);
            }
        } 
        while (i <= mid) cur.push_back(v[i++]);
        while (j <= r) cur.push_back(v[j++]);
        for (int k = l; k <= r; k++) {
            v[k] = cur[k - l];
        }
    }

    void merge_sort(vector<int> &v, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        merge_sort(v, l, mid);
        merge_sort(v, mid + 1, r);
        merge(v, l, mid, r);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};