class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> union_find;

        for (string s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            union_find[temp].push_back(s);
        }

        vector<vector<string>> return_vec;

        for (auto p : union_find) {
            return_vec.push_back(p.second);
        }

        return return_vec;
    }
};
