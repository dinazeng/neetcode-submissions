class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>, vector<string>> groups;
        
        for (string s : strs) {
            map<char, int> freq;
            for (char c : s) {
                freq[c]++;
            }

            if (groups.contains(freq)) {
                groups[freq].push_back(s);
            } else {
                groups[freq] = {s};
            }
        }

        vector<vector<string>> sol;

        for (auto &p : groups){
            sol.push_back(p.second);
        }

        return sol;
    }
};
