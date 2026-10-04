class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> adj;
        wordList.push_back(beginWord);
        int size = wordList.size();

        for (int i = 0; i < size; i++) {
            string word = wordList[i];
            for (int j = 0; j < size; j++) {
                if (j != i) {
                    int length = word.length();
                    int different = 0;
                    string comp = wordList[j];
                    int index = 0;
                    while (index < length && different <= 1) {
                        if (comp[index] != word[index]) {
                            different++;
                        }
                        index++;
                    }

                    if (different == 1 && index == length) {
                        adj[word].push_back(comp);
                        adj[comp].push_back(word);
                    }
                }
            }
        }

        map<string, bool> visited;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        visited[beginWord] = true;

        while (!q.empty()) {
            string processWord = q.front().first;
            int dist = q.front().second;

            q.pop();

            vector<string> neighbours = adj[processWord];
            for (string n : neighbours) {
                if (n == endWord) {
                    return dist + 1;
                } else if (!visited[n]) {
                    visited[n] = true;
                    q.push({n, dist + 1});
                }
            }
        }

        return 0;
    }
};
