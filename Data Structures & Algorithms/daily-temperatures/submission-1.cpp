class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int,int>> st;
        for (int i = 0; i < n; i++) {
            int cur_val = temperatures[i];
            while (!st.empty() and cur_val > st.top().first) {
                ans[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push(make_pair(cur_val, i));
        }
        return ans;
    }
};