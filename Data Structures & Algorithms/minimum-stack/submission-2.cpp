class MinStack {
public:
    stack<int> min_stack;
    stack<int> reg_stack;

    MinStack() {
        
    }
    
    void push(int val) {
        reg_stack.push(val);

        int value = min(val, min_stack.empty() ? val : min_stack.top());
        min_stack.push(value);
    }
    
    void pop() {
        reg_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return reg_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }   
};
