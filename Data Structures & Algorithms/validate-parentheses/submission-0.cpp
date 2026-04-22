class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' or ch == '{' or ch == '[') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                st.pop();
                if (ch == ')' and top != '(') {
                    return false;
                }
                if (ch == '}' and top != '{') {
                    return false;
                }
                if (ch == ']' and top != '[') {
                    return false;
                }
            }
        }
        return st.empty();
    }
};