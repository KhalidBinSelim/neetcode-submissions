class MinStack {
private:
    stack<int> main_st, min_st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        main_st.push(val);
        if (min_st.empty() or min_st.top() >= val) {
            min_st.push(val);
        } else {
            min_st.push(min_st.top());
        }
    }
    
    void pop() {
        main_st.pop();
        min_st.pop();
    }
    
    int top() {
        return main_st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */