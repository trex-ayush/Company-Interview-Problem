class Solution {
  public:
    void solve(vector<vector<int>>& mat, int i, int j, string temp, vector<string>& res){
        int n = mat.size();
        int m = mat[0].size();
        
        if(i < 0 || i >= n || j < 0 || j >= m || mat[i][j] != 1) return;
        if(i == n - 1 && j == m - 1){
            res.push_back(temp);
            return;
        }
        
        mat[i][j] = 2;
        
        solve(mat, i+1, j, temp + 'D', res);
        solve(mat, i, j+1, temp + 'R', res);
        solve(mat, i-1, j, temp + 'U', res);
        solve(mat, i, j-1, temp + 'L', res);
        
        mat[i][j] = 1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        if(maze[0][0] == 0) return {};
        vector<string> res;
        
        solve(maze, 0, 0, "", res);
        
        sort(res.begin(), res.end());
        return res;
    }
};