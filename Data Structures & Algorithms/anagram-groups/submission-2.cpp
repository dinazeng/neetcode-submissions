class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>, vector<string>> groups;
        
        for (string s : strs) {
            map<char, int> freq;
            for (char c : s) {
                freq[c]++;
            }

            groups[freq].push_back(s);
        }

        auto it = groups.begin();
        vector<vector<string>> sol;

        while (it != groups.end()){
            sol.push_back(it->second);
            it++;
        }

        return sol;
    }
};
