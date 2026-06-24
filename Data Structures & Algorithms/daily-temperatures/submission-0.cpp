class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> hotterDays;
        vector<int> answers(temperatures.size());

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            int todaysTemp = temperatures[i];
            int days = 0;
            while (!hotterDays.empty() && hotterDays.top().first <= todaysTemp) {
                hotterDays.pop();
            }

            answers[i] = hotterDays.empty() ? 0 : hotterDays.top().second - i;
            hotterDays.push({todaysTemp, i});
        }

        return answers;   
    }
};
