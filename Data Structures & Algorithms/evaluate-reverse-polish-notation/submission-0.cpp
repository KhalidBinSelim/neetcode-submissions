class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto str: tokens) {
            if (str == "+" or str == "-" or str == "*" or str == "/") {
                int top = st.top();
                st.pop();
                int second_top = st.top();
                st.pop();
                if (str == "+") {
                    st.push(second_top + top);
                } else if (str == "-") {
                    st.push(second_top - top);
                } else if (str == "*") {
                    st.push(second_top * top);
                } else if (str == "/") {
                    st.push(second_top / top);
                }
            } else {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};