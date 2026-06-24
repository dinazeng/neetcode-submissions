class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> union_find;

        for (string s : strs) {
            map<char, int> freq;

            for (char c: s) {
                freq[c]++;
            }

            if (union_find.contains(freq)) {
                union_find[freq].push_back(s);
            } else {
                union_find[freq] = {s};
            }
        }

        vector<vector<string>> return_vec;

        for (auto &p : union_find) {
            return_vec.push_back(p.second);
        }

        return return_vec;
    }
};
