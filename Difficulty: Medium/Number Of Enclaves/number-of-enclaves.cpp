class Solution {
public:
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>& board, int row, int col){
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()){
            return;
        }
        board[row][col] = INT_MIN;
        for(auto& dir : dirs){
            int new_i = row + dir[0];
            int new_j = col + dir[1];
            
            if (new_i >= 0 && new_i < board.size() && new_j >= 0 && new_j < board[0].size() && board[new_i][new_j] == 1) {
                dfs(board, new_i, new_j);
            }
            
        }
    }
    int numberOfEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < m; i++){
            // first row
            if(board[0][i] == 1) dfs(board, 0, i);
            // last row
            if(board[n-1][i] == 1) dfs(board, n-1, i);
        }
        for(int i = 0; i < n; i++){
            // first col
            if(board[i][0] == 1) dfs(board, i, 0);
            // last last
            if(board[i][m-1] == 1) dfs(board, i, m-1);
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == INT_MIN) board[i][j] = 0;                
            }
        }  
        int count = 0;
        for(auto& row : board){
            for(auto& r : row) {
                if(r == 1) count++;
            }
        }
        
        return count;
    }
};