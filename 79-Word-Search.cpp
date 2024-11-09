class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int i, int j, int ind){
        if(ind == word.length()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] == '*') return false;
        if(board[i][j] != word[ind]) return false;

        char temp = board[i][j];
        board[i][j] = '*';
        if(solve(board, word, i+1, j, ind+1)) return true;
        if(solve(board, word, i-1, j, ind+1)) return true;
        if(solve(board, word, i, j+1, ind+1)) return true;
        if(solve(board, word, i, j-1, ind+1)) return true;

        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int k =0;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == word[0]){
                   bool found = solve(board, word, i, j, 0);
                   if(found) return true;
                }
            }
        }
        return false;
    }
};