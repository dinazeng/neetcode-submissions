class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minK = 1;
        int maxK = *max_element(piles.begin(), piles.end());
        int result = maxK;

        while (minK <= maxK) {
            int k = (minK + maxK) / 2;

            long long time = 0;

            for (int p : piles) {
                time += ceil((double)p / k);
            }

            if (time <= h) {
                result = k;

                maxK = k - 1;
            } else {
                minK = k + 1;
            } 
        }

        return result;
    }
};
