class Solution {
public:
    int LENGTH;
    vector<string> letterCombinations(string digits) {
        LENGTH = digits.length();
        if (LENGTH == 0) {
            return {};
        }

        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> combos;

        int start = digits[0] - '0';
        for (const char& c : mapping[start]) {
            combos.push_back(string(1, c));
        }

        dfs(digits, combos, mapping, 1);

        return combos;
    }

    void dfs(string& digits, vector<string>& combos, vector<string>& mapping, int i) {
        if (i == LENGTH) return;

        int place = digits[i] - '0';
        vector<string> all_combos;
        for (const char& c : mapping[place]) {
            vector<string> temp = combos;
            for (string& s : temp) {
                s += c;
            }

            all_combos.insert(all_combos.end(), temp.begin(), temp.end());
        }

        combos = all_combos;

        dfs(digits, combos, mapping, i + 1);
    }
};
