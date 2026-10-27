
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word;

    TrieNode() {}

    void addWord(const string& word) {
        TrieNode* curr = this;

        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new TrieNode();
            }

            curr = curr->children[ch];
        }

        curr->word = word;
    }
};

class Solution {
public:
    vector<string> res;

    void dfs(vector<vector<char>>& board, int r, int c,
             TrieNode* node) {

        // Out of bounds or already visited
        if (r < 0 || c < 0 ||
            r >= board.size() || c >= board[0].size() ||
            board[r][c] == '#') {
            return;
        }

        char ch = board[r][c];

        // Does this character exist in the current Trie path?
        auto it = node->children.find(ch);

        if (it == node->children.end()) {
            return;
        }

        TrieNode* next = it->second;

        // A complete word has been found
        if (!next->word.empty()) {
            res.push_back(next->word);
            next->word = "";  // Avoid duplicate results
        }

        // Mark this cell as visited
        board[r][c] = '#';

        // Explore four directions
        dfs(board, r + 1, c, next);
        dfs(board, r - 1, c, next);
        dfs(board, r, c + 1, next);
        dfs(board, r, c - 1, next);

        // Backtrack: restore the original character
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        res.clear();

        if (board.empty() || board[0].empty()) {
            return res;
        }

        TrieNode* root = new TrieNode();

        // Build the Trie
        for (const string& str : words) {
            root->addWord(str);
        }

        // Start DFS from every board cell
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                dfs(board, r, c, root);
            }
        }

        return res;
    }
};
