class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }

        int climb1 = 1;
        int climb2 = 1;

        for (int i = 2; i <= n; i++) {
            int one = climb1;

            climb1 += climb2;
            climb2 = one;
        }


        return climb1;

    }
};
