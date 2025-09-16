// User function Template for C++

class Solution {
  public:
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>& board, int row, int col){
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()){
            return;
        }
        board[row][col] = '*';
        for(auto& dir : dirs){
            int new_i = row + dir[0];
            int new_j = col + dir[1];
            
            if (new_i >= 0 && new_i < board.size() && new_j >= 0 && new_j < board[0].size() && board[new_i][new_j] == 'O') {
                dfs(board, new_i, new_j);
            }
            
        }
    }
    vector<vector<char>> fill(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < m; i++){
            // first row
            if(board[0][i] == 'O') dfs(board, 0, i);
            // last row
            if(board[n-1][i] == 'O') dfs(board, n-1, i);
        }
        for(int i = 0; i < n; i++){
            // first col
            if(board[i][0] == 'O') dfs(board, i, 0);
            // last last
            if(board[i][m-1] == 'O') dfs(board, i, m-1);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '*') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }  
        return board;
    }
};