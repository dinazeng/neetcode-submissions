class MinStack {
public:
    stack<int> min_stack;
    stack<int> reg_stack;

    MinStack() {
        
    }
    
    void push(int val) {
        reg_stack.push(val);

        if (min_stack.empty() || min_stack.top() > val) {
            min_stack.push(val);

        } else {
            min_stack.push(min_stack.top());
        }
    }
    
    void pop() {
        if (!reg_stack.empty()) {
            reg_stack.pop();
            min_stack.pop();
        }
    }
    
    int top() {
        return reg_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }   
};
