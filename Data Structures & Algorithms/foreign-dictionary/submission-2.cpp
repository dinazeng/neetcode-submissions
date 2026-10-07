class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        map<char, set<char>> adj;
        set<char> all_characters;
        
        int word_list_size = words.size();

        for (string word : words) {
            for (char c : word) {
                all_characters.insert(c);
            }
        }

        int total_size = all_characters.size();

        for (int i = 0; i < word_list_size - 1; i++) {
            string word_one = words[i];
            string word_two = words[i + 1];

            int index = 0;
            int shorter_word = min(word_one.length(), word_two.length());
            while (index < shorter_word) {
                if (word_one[index] != word_two[index]) {
                    adj[word_one[index]].insert(word_two[index]);
                    all_characters.erase(word_two[index]);
                    break;
                }
                index++;
            }

            if (word_one.length() > word_two.length() && index == word_two.length()) {
                return "";
            }
        }

        map<char, int> indegrees;

        auto it = adj.begin();
        while (it != adj.end()) {
            char c = it->first;
            set<char> after = it->second;

            for (char a : after) {
                indegrees[a]++;
            }

            it++;
        }

        string solution = "";

        queue<char> q;
        for (char c : all_characters) {
            q.push(c);
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

        if (solution.length() != total_size) {
            return "";
        }

        return solution;
    }
};
