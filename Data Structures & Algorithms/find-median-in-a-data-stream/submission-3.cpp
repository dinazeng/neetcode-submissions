class MedianFinder {
public:
    priority_queue<int> bottom;
    priority_queue<int, vector<int>, greater<int>> top;

    MedianFinder() {    
        
    }
    
    void addNum(int num) {
       if (bottom.size() == top.size()) {
            top.push(num);
            bottom.push(top.top());
            top.pop();
        } else {
            bottom.push(num);
            top.push(bottom.top());
            bottom.pop();
        }
    }
    
    double findMedian() {
        if (bottom.size() == top.size()) {
           return (top.top() + bottom.top()) / 2.0;
        }

        return (double) bottom.top();
    }
};
