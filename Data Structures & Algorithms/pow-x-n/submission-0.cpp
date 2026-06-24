class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        } else if (n > 0 ){
            return x * myPow(x, n - 1);
        } else {
            return myPow(x, n + 1) / x;
        }
    }
};
