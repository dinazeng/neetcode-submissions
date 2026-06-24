class MinStack {
public:
    stack<int> stack_stack;
    stack<int> min_stack;

    MinStack() {}
    
    void push(int val) {
        stack_stack.push(val);

        int value = min(val, min_stack.empty() ? val : min_stack.top());
        
        min_stack.push(value);
    }
    
    void pop() {
        stack_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return stack_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
