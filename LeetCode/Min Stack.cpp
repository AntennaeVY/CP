class MinStack {
    int _min = INT_MAX;
    stack<pair<int, int>> state;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (state.empty())
            return state.push({val, val});
    
        auto [top, mn] = state.top();
        state.push({val, min(mn, val)});
    }
    
    void pop() {
        if (!state.empty())
            state.pop();
    }
    
    int top() {
        return state.top().first;
    }
    
    int getMin() {
        return state.top().second;
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