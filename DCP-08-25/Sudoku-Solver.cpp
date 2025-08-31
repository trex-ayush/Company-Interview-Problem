// Company tags: Adobe, Amazon, Apple, Bloomberg, Citadel, DoorDash, Intuit, Meta, Microsoft, Oracle, Pinterest, Snap, Uber, Yahoo
class Solution {
public:
    // Time Complexity	: O(1) (constant, due to fixed 9x9 board)
    // Space Complexity : O(1) (in-place + recursion, capped at 81 levels)
    bool isValid(vector<vector<char>> &mat, int row, int col, int num){
        char c = num + '0';
        for(int i = 0; i < 9; i++){
            if(mat[row][i] == c) return false;
            if(mat[i][col] == c) return false;
            if(mat[(row/3)*3 + i/3][(col/3)*3 + i%3] == c) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> &mat){
        int n = mat.size();
        int m = mat[0].size();
        
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                if(mat[row][col] == '.'){
                    for(int num = 1; num <= 9; num++){
                        if(isValid(mat,row,col,num)){
                            mat[row][col] = num + '0';
                            if(solve(mat)) return true;
                            mat[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};