class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int size = words.size();
        vector<vector<char>> adj(26);
        vector<int> degrees(26, -1);
        set<char> seen_this_char;

        for (string word : words) {
            for (char c : word) {
                seen_this_char.insert(c);
                degrees[c - 'a'] = 0;
            }
        }

        for (int i = 1; i < size; i++) {
            string word_one = words[i - 1];
            string word_two = words[i];
            int length = min(word_two.length(), word_one.length());
            int index_diff = 0;
            for (int j = 0; j < length; j++) {
                if (word_two[j] != word_one[j]) {
                    break;
                }
                index_diff++;
            }

            if (index_diff == length) {
                if (word_two.length() < word_one.length()) return "";
                continue;
            }

            adj[words[i - 1][index_diff] - 'a'].push_back(word_two[index_diff]);
            degrees[word_two[index_diff] - 'a']++;
        }

        queue<char> q;
        string seen = "";

        for (int i = 0; i < 26; i++) {
            if (degrees[i] == 0) {
                q.push(i + 'a');
            }
        }

        while (!q.empty()) {
            char c = q.front();
            q.pop();

            if (seen.contains(c)) {
                return "";
            }

            seen += c;

            int val = c - 'a';

            for (char n : adj[val]) {
                degrees[n - 'a']--;
                if (degrees[n - 'a'] == 0) {
                    q.push(n);
                }
            }
        }


        return seen.length() == seen_this_char.size() ? seen : "";
    }
};
