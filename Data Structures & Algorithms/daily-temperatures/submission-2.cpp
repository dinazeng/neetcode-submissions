class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();

        vector<int> days (size);
        stack<pair<int,int>> temps;

        for (int i = size - 1; i >= 0; i--) {
            int today = temperatures[i];
            while (!temps.empty() && temps.top().first <= today) {
                temps.pop();
            }

            days[i] = temps.empty() ? 0 : temps.top().second - i;
            temps.push({today, i});
        }

        return days;
    }
};
