// Company tags: Adobe, Amazon, Apple, Autodesk, Bloomberg, DoorDash, Geico, Goldman Sachs, Instacart, Karat, Media.net, Meta, Microsoft, MongoDB, Nvidia, Oracle, Snap, TikTok, Uber, Walmart Labs, Yahoo, Yandex, Zoho
class Solution {
public:
    // Time Complexity  : O(81 + 81 + 81) = O(243) ≈ O(1)
    // Space Complexity : O(9) → considered constant → O(1)
    bool validate(vector<vector<char>>& mat, int sr, int er, int sc, int ec){
        unordered_set<char> set;
        for(int i = sr; i <= er; i++){
            for(int j = sc; j <= ec; j++){
                if(mat[i][j] == '.') continue;
                if(set.find(mat[i][j]) != set.end()) return false;
                set.insert(mat[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& mat) {
        // validate row
        for(int row = 0; row < 9; row++){
            unordered_set<char> set;
            for(int col = 0; col < 9; col++){
                if(mat[row][col] == '.') continue;
                if(set.find(mat[row][col]) != set.end()) return false;
                set.insert(mat[row][col]);
            }
        }
        // validate col
        for(int col = 0; col < 9; col++){
            unordered_set<char> set;
            for(int row = 0; row < 9; row++){
                if(mat[row][col] == '.') continue;
                if(set.find(mat[row][col]) != set.end()) return false;
                set.insert(mat[row][col]);
            }
        }
        // validate 3x3 box
        for(int sr = 0; sr < 9; sr += 3){
            int er = sr + 2;
            for(int sc = 0; sc < 9; sc += 3){
                int ec = sc + 2;
                if(validate(mat, sr, er, sc, ec) == false) return false;
            }
        }
        return true;
    }
};