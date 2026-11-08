class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_speed = 1;
        int max_speed = *max_element(piles.begin(), piles.end());

        while (min_speed <= max_speed) {
            int tryK = (min_speed + max_speed) / 2;

            long long hours_needed = 0;
            for (const int& p : piles) {
                hours_needed += ceil((double) p / tryK);
            }

            if (hours_needed <= h) {
                max_speed = tryK - 1;
            } else {
                min_speed = tryK + 1;
            }
        }

        return min_speed;
    }
};
