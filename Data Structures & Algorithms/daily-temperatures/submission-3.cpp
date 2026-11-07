class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        if (size == 0) {
            return {};
        }

        vector<int> temps(size);
        temps[size - 1] = 0;

        stack<pair<int, int>> next;
        next.push({size - 1, temperatures[size - 1]});

        for (int i = size - 2; i >= 0; i--) {
            int curr_temp = temperatures[i];
            while (!next.empty() && next.top().second <= curr_temp) {
                next.pop();
            }

            if (next.empty()) {
                temps[i] = 0;
            } else {
                temps[i] = next.top().first - i;
            }

            next.push({i, curr_temp});
        }

        return temps;
    }
};
