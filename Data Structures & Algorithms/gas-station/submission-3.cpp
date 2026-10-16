class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }

        int size = gas.size();

        int balance = 0;
        int start = 0;

        for (int i = 0; i < size; i++) {
            balance += gas[i] - cost[i];

            if (balance < 0) {
                start = i + 1;
                balance = 0;
            }
        }

        return start;
    }
};
