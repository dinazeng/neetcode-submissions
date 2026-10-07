class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegrees;
        
        int word_list_size = words.size();

        for (string word : words) {
            for (char c : word) {
                adj[c] = unordered_set<char>();
                indegrees[c] = 0;

            }
        }

        for (int i = 0; i < word_list_size - 1; i++) {
            string word_one = words[i];
            string word_two = words[i + 1];

            int index = 0;
            int shorter_word = min(word_one.length(), word_two.length());
            while (index < shorter_word) {
                if (word_one[index] != word_two[index]) {
                    adj[word_one[index]].insert(word_two[index]);
                    break;
                }
                index++;
            }

            if (word_one.length() > word_two.length() && index == word_two.length()) {
                return "";
            }
        }

        auto it = adj.begin();
        while (it != adj.end()) {
            char c = it->first;
            unordered_set<char> after = it->second;

            for (char a : after) {
                indegrees[a]++;
            }

            it++;
        }

        string solution = "";

        queue<char> q;
        for (auto &[c, d] : indegrees) {
            if (d == 0) {
                q.push(c);
            }
        }

        while (!q.empty()) {
            char process = q.front();
            q.pop();

            solution += process;

            for (char c : adj[process]) {
                indegrees[c]--;

                if (indegrees[c] == 0) {
                    q.push(c);
                }
            }
        }

        if (solution.length() != adj.size()) {
            return "";
        }

        return solution;
    }
};
