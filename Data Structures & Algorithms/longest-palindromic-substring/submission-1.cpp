class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        int max = 0;    
        string sol = "";

        for (int i = 0; i < length; i++) {
            int count = processPalindromeCycles(i - 1, i + 1, length, s) * 2 + 1;
            
            if (count > max) {
                max = count;
                sol = s.substr(i - (count - 1)/2, count);
            }

            int next = i + 1;
            if (next < length && s[next] == s[i]) {
                int count = processPalindromeCycles(i - 1, i + 2, length, s) *2 + 2;
                if (count > max) {
                    max = count;
                    sol = s.substr(i - (count - 2)/2, count);
                }
            }
        }

        return sol;
    }

    int processPalindromeCycles (int left, int right, int length, string &s) {
        int count = 0;
        while (left >= 0 && right < length && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }

        return count;
    }
};
