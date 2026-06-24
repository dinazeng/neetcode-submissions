class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.length();
        int size_half = size/2;

        int left = 0;
        int right = size - 1;

        while (left <= right) {
            char left_char = tolower(s[left]);
            char right_char = tolower(s[right]);

            if (!(left_char >= 'a' && left_char <= 'z') && ! (left_char >= '0' && left_char <= '9')) {
                left++;
            } else if (!(right_char >= 'a' && right_char <= 'z') && !(right_char >= '0' && right_char <= '9')) {
                right--;
            } else {
                if (left_char != right_char) {
                    return false;
                }

                left++;
                right--;
            }
        }

        return true;
    }
};
