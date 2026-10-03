class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map <char, vector<string>> mapping;
        mapping['2'] = {"a", "b", "c"};
        mapping['3'] = {"d", "e", "f"};
        mapping['4'] = {"g", "h", "i"};
        mapping['5'] = {"j", "k", "l"};
        mapping['6'] = {"m", "n", "o"};
        mapping['7'] = {"p", "q", "r", "s"};
        mapping['8'] = {"t", "u", "v"};
        mapping['9'] = {"w", "x", "y", "z"};

        if (digits.length() == 0) {
            return {};
        }

        vector<string> results = mapping[digits[0]];
        
        for (int i = 1; i < digits.size(); i++) {
            process(results, digits[i], mapping);
        }

        return results;
    }

    void process (vector<string> &curr, char digit, map<char, vector<string>> &mapping) {
        vector<string> m = mapping[digit];
        vector<string> curr_copy;
        for (string c : m) {
            vector<string> temp = curr;
            for (int i = 0; i < temp.size(); i++) {
                temp[i] = temp[i] + c;
            }

            curr_copy.insert(curr_copy.end(), temp.begin(), temp.end());
        }

        curr = curr_copy;
    }
};
