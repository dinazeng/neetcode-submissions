class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int length = digits.length();
        if (length == 0) {
            return {};
        }

        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> combos;

        int first = digits[0] - '0';
        for (const char &c : mapping[first]) {
            combos.push_back(string(1, c));
        }

        dfs(mapping, digits, combos, 1);

        return combos;
    }

    void dfs(vector<string>& mapping, string& digits, vector<string>& combos, int index) {
        if (index == digits.length()) {
            return;
        }

        int place = digits[index] - '0';
        
        vector<string> temp_all;
        for (const char &c : mapping[place]) {
            vector<string> temp = combos;
            for (string& st : temp) {
                st += c;
            }

            temp_all.insert(temp_all.end(), temp.begin(), temp.end());
        }

        combos = temp_all;
        dfs(mapping, digits, combos, index + 1);
    }
};
