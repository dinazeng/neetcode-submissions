class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }

        vector<int> climbs(n + 1);

        climbs[0] = 1;
        climbs[1] = 1;

        for (int i = 2; i <= n; i++) {
            climbs[i] = climbs[i - 1] + climbs[i - 2]; 
        }


        return climbs[n];

    }
};
