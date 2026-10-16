class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        vector<bool> possible(size + 1);
        possible[0] = true;
        for (int i = 0; i < size; i++) {
            if (possible[i]) {
                for (string &sub : wordDict) {
                    int length = sub.length();

                    if (i + length > size) continue; 

                    if (s.substr(i, length) == sub) {

                        possible[i + length] = true;
                    }
                }
            }
        }

        return possible[size];
    }
};
