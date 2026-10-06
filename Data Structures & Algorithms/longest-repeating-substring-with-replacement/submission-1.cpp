class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.length();
        int maxf = 0;
        int l = 0;
        int res = 0;
        map<char, int> freq;

        for (int r = 0; r < size; r++) {
            freq[s[r]]++;
            maxf = max(maxf, freq[s[r]]);

            while (r - l + 1 - maxf > k) {
                freq[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }

        return res;
    } 
};
