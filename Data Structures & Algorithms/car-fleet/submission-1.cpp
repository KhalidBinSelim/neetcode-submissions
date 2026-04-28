class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pr;
        int n = position.size();
        for (int i = 0; i < n; i++) {
            pr.push_back({position[i], speed[i]});
        }
        sort(pr.rbegin(), pr.rend());
        vector<double> st;
        for (auto [x, y] : pr) {
            double time = 1.0 * (target - x) / y;
            st.push_back((time));
            if (st.size() >= 2 and st.back() <= st[st.size() - 2]) st.pop_back();
        }
        return st.size();
    }
};