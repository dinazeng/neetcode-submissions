class MedianFinder {
public:

    priority_queue<int> bottom_half;
    priority_queue<int, vector<int>, greater<int>> top_half;
    int size = 0;

    MedianFinder() {
        
    }

    void addNum(int num) {
        size++;
        if (bottom_half.size() == top_half.size()) {
            if (!top_half.empty() && top_half.top() < num) {
                bottom_half.push(top_half.top());
                top_half.pop();
                top_half.push(num);
            } else {
                bottom_half.push(num);
            }
        } else {
            if (!bottom_half.empty() && bottom_half.top() > num) {
                top_half.push(bottom_half.top());
                bottom_half.pop();
                bottom_half.push(num);
            } else {
                top_half.push(num);
            }
        }
    }
    
    double findMedian() {
        int half = size / 2;
        if (size % 2 == 0) {
            return (bottom_half.top()  + top_half.top()) / 2.0;
        }

        return bottom_half.top();
    }
};
