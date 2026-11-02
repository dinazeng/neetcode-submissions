class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> big (stones.begin(), stones.end());
        
        while (big.size() >= 2) {
            int one = big.top();
            big.pop();
            int two = big.top();
            big.pop();

            big.push(one - two);
        }

        return big.top();
    }
};
