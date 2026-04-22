class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> p;
        for (int i = 0; i < speed.size(); i++) {
            p.push_back(make_pair(position[i], speed[i]));
        }
        sort(p.rbegin(), p.rend());
        vector<double> st;
        for (auto [x, y]: p) {
            double time = (1.0 * (target - x)) / y;
            st.push_back(time);
            if (st.size() >= 2 and st.back() <= st[st.size() - 2]) st.pop_back();
        }
        return st.size();
    }
};