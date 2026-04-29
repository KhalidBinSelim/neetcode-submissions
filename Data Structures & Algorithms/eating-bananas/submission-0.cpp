class Solution {
public:
    bool f(vector<int>& piles, int mid, int h) {
        int total = 0;
        for (int p : piles) {
            total += ceil(1.0 * p / mid);
        }
        return total <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int l = 1, r = piles[piles.size() - 1];
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (f(piles, mid, h)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};