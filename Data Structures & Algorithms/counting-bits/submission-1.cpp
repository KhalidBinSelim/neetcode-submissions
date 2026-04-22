class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int num = i, cnt = 0;
            while (num != 0) {
                num &= num - 1;
                cnt++;
            }
            res[i] = cnt;
        }
        return res;
    }
};