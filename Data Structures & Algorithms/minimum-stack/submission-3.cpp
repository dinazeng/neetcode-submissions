class MinStack {
public:
    stack<int> real;
    stack<int> smol;

    MinStack() {
        
    }
    
    void push(int val) {
        real.push(val);
        
        int smolest = smol.empty() || smol.top() > val ? val : smol.top();

        smol.push(smolest);
    }       
    
    void pop() {
        smol.pop();
        real.pop();
    }
    
    int top() {
        return real.top();
    }
    
    int getMin() {
        return smol.top();
    }
};
