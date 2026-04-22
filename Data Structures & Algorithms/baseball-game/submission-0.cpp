class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (auto str: operations) {
            if (str == "C" and !st.empty()) {
                st.pop();
            } else if (str == "D" and !st.empty()) {
                st.push(2 * st.top());
            } else if (str == "+" and !st.empty()) {
                int last = (st.top());
                st.pop();
                int second_last = (st.top());
                st.push(last);
                st.push(last + second_last);
            } else {
                st.push(stoi(str));
            }
        }
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};