class Trie {
public:
    unordered_map<int, Trie*> child; 
    bool endOfWord = false;
    Trie(){}
};

class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* index = root;
        for (char c : word) {
            int i = c - 'a';
            if (!index->child.contains(i)) {
                index->child[i] = new Trie();
            }

            index = index->child[i];
        }

        index->endOfWord = true;
    }
    
    bool search(string word) {
        vector <Trie*> level;
        level.push_back(root);

        for (char c : word) {
            if (level.empty()) {
                return false;
            }

            if (c == '.') {
                vector<Trie*> newLevel;
                for (auto l : level) {
                    for (auto c : l->child) {
                        newLevel.push_back(c.second);
                    }
                }

                level = newLevel;
            } else {
                int i = c - 'a';
                vector<Trie*> newLevel;
                for (auto l : level) {
                    if (l->child.contains(i)) {
                        newLevel.push_back(l->child[i]);
                    }
                }

                level = newLevel;
            }
        }

        for (auto l : level) {
            if (l->endOfWord) {
                return true;
            }
        }

        return false;
    }
};
