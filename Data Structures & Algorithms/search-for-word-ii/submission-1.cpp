
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

  
void dfs(vector<vector<char>>& board,
         vector<vector<bool>>& visited,
         int r, int c, TrieNode* node) {

    // Check boundaries and whether the cell is already visited
    if (r < 0 || c < 0 ||
        r >= board.size() || c >= board[0].size() ||
        visited[r][c]) {
        return;
    }

    char ch = board[r][c];

    // Check whether this character exists in the Trie path
    auto it = node->children.find(ch);

    if (it == node->children.end()) {
        return;
    }

    TrieNode* next = it->second;

    // Found a complete word
    if (!next->word.empty()) {
        res.push_back(next->word);
        next->word = "";
    }

    // Mark this cell as visited for the current path
    visited[r][c] = true;

    // Explore four directions
    dfs(board, visited, r + 1, c, next);
    dfs(board, visited, r - 1, c, next);
    dfs(board, visited, r, c + 1, next);
    dfs(board, visited, r, c - 1, next);

    // Backtrack: make this cell available again
    visited[r][c] = false;
}


   
vector<string> findWords(vector<vector<char>>& board,
                         vector<string>& words) {
    res.clear();

    if (board.empty() || board[0].empty()) {
        return res;
    }

    TrieNode* root = new TrieNode();

    for (const string& word : words) {
        root->addWord(word);
    }

    int row = board.size();
    int col = board[0].size(); 
    vector<vector<bool>> visited(row,vector<bool>(col));
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            visited[i][j] = false;
        }
    }


    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            dfs(board, visited, r, c, root);
        }
    }

    return res;
}

};
