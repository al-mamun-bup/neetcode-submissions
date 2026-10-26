
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
    queue<TrieNode*> q;
    q.push(root);

    for (char ch : word) {
        int sz = q.size();

        for (int i = 0; i < sz; i++) {
            TrieNode* curr = q.front();
            q.pop();

            if (ch == '.') {
                // Wildcard: try every existing child
                for (auto& [key, child] : curr->children) {
                    q.push(child);
                }
            } else {
                // Normal character: follow only the matching child
                auto it = curr->children.find(ch);

                if (it != curr->children.end()) {
                    q.push(it->second);
                }
            }
        }

        // No possible paths remain
        if (q.empty()) {
            return false;
        }
    }

    // Check whether any remaining node ends a complete word
    while (!q.empty()) {
        TrieNode* curr = q.front();
        q.pop();

        if (curr->isEnd) {
            return true;
        }
    }

    return false;
}
};
