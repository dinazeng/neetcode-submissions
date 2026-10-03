class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int length = digits.length();
        if (length == 0) {
            return {};
        }

        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl","mno", "qprs", "tuv", "wxyz"};
        vector<string> results;

        string start = mapping[digits[0] - '0'];
        for (int i = 0; i < start.size(); i++) {
            results.push_back(start.substr(i, 1));
        }
        
        for (int i = 1; i < length; i++) {
            process(results, mapping[digits[i] - '0']);
        }

        return results;
    }

    void process (vector<string> &curr, string &mapping) {
        vector<string> curr_copy;
        int curr_size = curr.size();
        for (char c : mapping) {
            vector<string> temp = curr;
            for (int i = 0; i < curr_size; i++) {
                temp[i] = temp[i] + c;
            }

            curr_copy.insert(curr_copy.end(), temp.begin(), temp.end());
        }

        curr = curr_copy;
    }
};
