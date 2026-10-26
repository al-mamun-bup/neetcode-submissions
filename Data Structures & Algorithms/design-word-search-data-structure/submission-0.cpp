
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode() {
        isEnd = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new TrieNode();
            }

            curr = curr->children[ch];
        }

        curr->isEnd = true;
    }

    bool search(string word) {
        vector<TrieNode*> currNodes = {root};

        for (char ch : word) {
            vector<TrieNode*> nextNodes;

            for (TrieNode* curr : currNodes) {
                if (ch == '.') {
                    for (auto& [key, child] : curr->children) {
                        nextNodes.push_back(child);
                    }
                } else {
                    auto it = curr->children.find(ch);

                    if (it != curr->children.end()) {
                        nextNodes.push_back(it->second);
                    }
                }
            }

            currNodes = nextNodes;

            if (currNodes.empty()) {
                return false;
            }
        }

        for (TrieNode* curr : currNodes) {
            if (curr->isEnd) {
                return true;
            }
        }

        return false;
    }
};
