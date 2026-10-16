class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);

        int size = wordList.size();
        int string_sizes = beginWord.size();

        unordered_map<string, vector<string>> neighbour;
        unordered_map<string, bool> visited;

        for (int i = 0; i < size; i++) {
            string word_one = wordList[i];
            for (int j = i + 1; j < size; j++) {
                string word_two = wordList[j];
                int diff = 0;

                for (int k = 0; k < string_sizes; k++) {
                    if (word_one[k] != word_two[k]) {
                        diff++;
                    }
                }

                if (diff == 1) {
                    neighbour[word_one].push_back(word_two);
                    neighbour[word_two].push_back(word_one);
                }
            }
        }

        if (!neighbour.contains(endWord)) return 0;

        queue<pair<string, int>> q;
        visited[beginWord] = true;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            string word = p.first;
            int dist = p.second;

            if (word == endWord) {
                return dist;
            }

            for (string &nei : neighbour[word]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push({nei, dist + 1});
                }
            }
        }

        return 0;
    }
};
