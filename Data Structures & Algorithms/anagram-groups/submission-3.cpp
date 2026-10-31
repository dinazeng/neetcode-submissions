class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> groups;
        
        for (string s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            groups[sorted].push_back(s);
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
