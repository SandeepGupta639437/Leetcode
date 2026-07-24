class MinStack {
public:
    stack<int>st,mini;
    MinStack() {
        mini.push(INT_MAX);
    }
    
    void push(int value) {
        st.push(value);
        mini.push(min(mini.top(),value));
    }
    
    void pop() {
        st.pop();
        mini.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */