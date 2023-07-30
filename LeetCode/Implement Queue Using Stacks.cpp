class MyQueue {
private:
    stack<int> push_state, pop_state;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        push_state.push(x);
    }
    
    int pop() {
        int x = peek();
        pop_state.pop();

        return x;
    }
    
    int peek() {
        if (pop_state.empty()) {
            while(!push_state.empty()) {
                pop_state.push(push_state.top());
                push_state.pop();
            }
        }

        return pop_state.top();
    }
    
    bool empty() {
        return push_state.empty() && pop_state.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */