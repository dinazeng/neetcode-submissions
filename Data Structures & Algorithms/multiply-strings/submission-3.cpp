class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int length_num1 = num1.size();
        reverse(num1.begin(), num1.end());

        int length_num2 = num2.length();
        reverse(num2.begin(), num2.end());

        vector<int> result (length_num1 + length_num2);

        for (int i = 0; i < length_num1; i++) {
            for (int j = 0; j < length_num2; j++) {
                int digit = (num1[i] - '0') * (num2[j] - '0');

                result[i + j] += digit;
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] %= 10;
            }
        }

        stringstream res;
        int i = result.size() - 1;
        while (i >= 0 && result[i] == 0) {
            i--;
        }

        while (i >= 0) {
            res << result[i--];
        }
        
        return res.str(); 
    }
};
