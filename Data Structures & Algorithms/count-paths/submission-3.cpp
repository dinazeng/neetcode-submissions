class Solution {
public:
    int uniquePaths(int m, int n) {
        long factorial = 1;
        int choose = 1;
        for (int i = m; i < m + n - 1; i++) {
            factorial *= i;
            factorial /= choose;
            choose++;
        }

        return factorial;
    }
};
