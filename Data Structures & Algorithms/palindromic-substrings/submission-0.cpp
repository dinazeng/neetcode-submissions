class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int length = s.length();

        for (int i = 0; i < length; i++) {
            count++;
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 & right <= length && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }

            int next = i + 1;
            if (next < length && s[i] == s[next]) {
                count++;
                int left = i - 1;
                int right = next + 1;

                while (left >= 0 & right <= length && s[left] == s[right]) {
                    count++;
                    left--;
                    right++;
                }
            }
        }

        return count;
    }
};
