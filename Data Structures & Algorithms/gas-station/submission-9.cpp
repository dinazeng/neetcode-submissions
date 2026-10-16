class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();

        int total_gas = 0;
        int balance = 0;
        int start = 0;

        for (int i = 0; i < size; i++) {
            int net_gas = gas[i] - cost[i];

            balance += net_gas;
            total_gas += net_gas;

            if (balance < 0) {
                start = i + 1;
                balance = 0;
            }
        }

        if (total_gas < 0) {
            return -1;
        }

        return start;
    }
};
