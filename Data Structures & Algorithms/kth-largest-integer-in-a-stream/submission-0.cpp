class KthLargest {
public:
    vector<int> v;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this -> v = nums;
        this -> k = k;
    }
    int add(int val) {
        v.push_back(val);
        sort(v.begin(), v.end());
        return v[v.size() - k];
    }
};
