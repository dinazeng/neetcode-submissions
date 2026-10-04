class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        int size = position.size();
        for (int i = 0; i < size; i++) {
            v.push_back({position[i], speed[i]});
        }

        sort(v.rbegin(), v.rend());

        int count = 1;
        double prevTime = (double)(target - v[0].first) / v[0].second;
        for (int i = 1; i < size; i ++) {
            double currTime = (double)(target - v[i].first) / v[i].second;
            if (currTime > prevTime ) {
                count++;
                prevTime = currTime;
            }
        }


        return count;
    }
};
