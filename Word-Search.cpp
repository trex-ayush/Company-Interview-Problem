// Company tags: Adobe, Amazon, Apple, Atlassian, Bloomberg, Capital One, Cisco, Citadel, Epic Systems, Goldman Sachs, Grammarly, Karat, Meta, Microsoft, Oracle, PayPal, Paytm, Roblox, Samsung, Snap, TCS, TikTok, Uber, Visa, Walmart Labs, Wix, Zepto, Zoho
class Solution {
public:
    // Time complexity  : O(n * m * 4^L)
    // Space complexity : O(L)
    vector<vector<int>> dirs = {{1,0}, {-1, 0}, {0,1}, {0, -1}};
    bool solve(vector<vector<char>>& mat, string& word, int i, int j, int wordIdx){
        int n = mat.size();
        int m = mat[0].size();
        
        if(i >= n || i < 0 || j >= m || j < 0 || mat[i][j] != word[wordIdx] || mat[i][j] == '*') return false;
        if(wordIdx == word.length() - 1) return true;
        
        char temp = mat[i][j];
        mat[i][j] = '*';
        
        for(auto& dir : dirs){
            int x = i + dir[0];
            int y = j + dir[1];
            if(solve(mat, word, x, y, wordIdx+1)) return true;
        }
        
        mat[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& mat, string word) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(word[0] == mat[i][j]){
                    if(solve(mat, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};