class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int lowest = high;
        
        while (low <= high) {
            int tryK = (low + high)/2;
            long long hours = 0;

            for (const int& p : piles) {
                hours += ceil((double)p/tryK);
            }

            if (hours <= h) {
                lowest = tryK;
                high = tryK - 1;
            } else {
                low = tryK + 1;
            }
        }

        return lowest;
    }
};
