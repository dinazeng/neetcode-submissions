class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_fives = 0;
        int count_tens = 0;

        for (int &b : bills) {
            if (b == 5) {
                count_fives++;
            } else {
                if (b == 10) {
                    count_fives--;
                    count_tens++;
                } else if (count_tens >= 1) {
                        count_tens--;
                        count_fives--;
                } else {
                    count_fives -= 3;
                }

                if (count_fives < 0 || count_tens < 0) {
                    return false;
                }
            }
        }  

        return true;
    }
};