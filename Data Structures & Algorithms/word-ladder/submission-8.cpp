class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int size = wordList.size();
        int word_size = beginWord.size();

        unordered_map<string, vector<string>> adj;

        for (int i = 0; i < size; i++) {
            string word_1 = wordList[i];
            for (int j = i + 1; j < size; j++) {
                string word_2 = wordList[j];
            
                int diff = 0;
                for (int k = 0; k < word_size; k++) {
                    if (word_1[k] != word_2[k]) {
                        diff++;
                    }
                }

                if (diff == 1) {
                    adj[word_1].push_back(word_2);
                    adj[word_2].push_back(word_1);
                }
            }
        }

        set<string> visited;
        queue<pair<string, int>> q;

        visited.insert(beginWord);
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto front = q.front();
            string word = front.first;
            int dist = front.second;
            q.pop();
            
            if (word == endWord) {
                return dist;
            }


            for (string &next : adj[word]) {
                if (!visited.contains(next)) {
                    visited.insert(next);
                    q.push({next, dist + 1});
                }
            }
        } 

        return 0;
    }
};
