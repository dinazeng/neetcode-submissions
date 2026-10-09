class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        int max_size = 0;
        string sol = "";

        for (int i = 0; i < length; i++) {
            int count = processPalindromeCycles( i - 1, i + 1, s, length) * 2 + 1;
            
            if (count > max_size) {
                max_size = count;
                sol = s.substr(i - (count - 1)/2, count);
            }

            int next = i + 1;
            if (next < length && s[next] == s[i]) {
                int count = processPalindromeCycles(i - 1, i + 2, s, length) *2 + 2;
                if (count > max_size) {
                    max_size = count;
                    sol = s.substr(i - (count - 2)/2, count);
                }
            }
        }

        return sol;
    }

    int processPalindromeCycles (int left, int right, string &s, int length) {
        int count = 0;
        while (left >= 0 && right < length && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }

        return count;
    }
};