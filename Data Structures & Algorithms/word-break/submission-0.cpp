class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.length();
        vector<bool> dict(size + 1, false);

        dict[0] = true;

        for (int right = 0; right < size; right++) {
            for (string w : wordDict) {
                int length = w.length();

                int left = right - length + 1;

                if (left >= 0) {
                    string substr = s.substr(left, length);
                    if (substr == w && dict[left]) {
                        dict[right + 1] = true;
                    }
                }
            }
        }

        return dict[size];
    }
};
