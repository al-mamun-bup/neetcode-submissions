class Solution {
public:
    set<pair<int,int>>visited;

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int r = 0; r < n ; r++){
            for(int c = 0; c < m; c++){
                if(dfs(board,word,r,c,0)){
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int idx){
        if(idx == word.size()){
            return true;
        }
        
        if(r < 0 or c < 0 or r >= board.size() or c >= board[0].size()
            or board[r][c] != word[idx] or visited.count({r,c})== true){
                return false;
        }

        visited.insert({r,c});
        bool result = ( dfs(board,word,r+1,c, idx+1) || dfs(board,word,r-1,c, idx+1) 
        || dfs(board,word,r,c+1, idx+1) || dfs(board,word,r,c-1, idx+1) );

        visited.erase({r,c});

        return result;
        
    }
};
