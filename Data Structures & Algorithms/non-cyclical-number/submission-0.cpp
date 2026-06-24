class Solution {
public:
    bool isHappy(int n) {
        set<int> seen;

        while (n != 1) {
            int sum = 0;
            while (n != 0) {
                int square = n % 10;
                sum += square*square;
                n /= 10;
            }

            if (seen.find(sum) != seen.end()) {
                return false;
            }

            seen.insert(sum);

            n = sum;
        }

        return true;
    }
};
