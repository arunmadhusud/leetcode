class MinStack {
public:
    // Stack to store pairs of (value, min_value_at_that_point)
    stack<pair<int, int>> st;

    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            // If stack is empty, initialize the min to the value being pushed
            st.push({val, val});
        } else {
            // Get the current minimum value from the top of the stack
            int current_min = st.top().second;
            // Push the new value with the minimum of the current value and the previous minimum
            st.push({val, min(val, current_min)});
        }
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }
    
    int top() {
        if (!st.empty()) {
            return st.top().first;
        }
        throw runtime_error("Stack is empty");
    }
    
    int getMin() {
        if (!st.empty()) {
            return st.top().second;
        }
        throw runtime_error("Stack is empty");
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