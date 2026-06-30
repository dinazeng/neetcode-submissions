class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int minSpeed = right;

        while (left <= right) {
            int tryK = (left + right)/2;
            long long hours = 0;

            for (int p : piles) {
                hours += ceil((double) p / tryK);
            }

            if (hours <= h) {
                minSpeed = tryK;
                right = tryK - 1;
            } else {
                left = tryK + 1;
            }

        }

        return minSpeed;
    }
};
