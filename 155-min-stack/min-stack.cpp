class MinStack {
public:
    std::stack<pair<int,int>> st;
    int min_elem;
    MinStack() { 
        min_elem = INT_MAX;    
    }
    
    void push(int val) {
        if (st.empty()) min_elem = val;
        else min_elem = min(st.top().second, val);
        st.push({val, min_elem});      
    }
    
    void pop() {
        if(!st.empty()) st.pop();
      
        
    }
    
    int top() {
        if(!st.empty()) return st.top().first;
        else return -1;        
    }
    
    int getMin() {
        return st.top().second;
        
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