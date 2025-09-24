class Solution {
  public:
    int solve(vector<vector<int>>& triangle, int idx, int level, vector<vector<int>>& t){
        int n = triangle.size();
        if(level == n - 1) return triangle[level][idx];
        
        if(t[level][idx] != -1) return t[level][idx];
        
        int down = solve(triangle, idx, level + 1, t);
        int downRight = solve(triangle, idx + 1, level + 1, t);
        
        return t[level][idx] = triangle[level][idx] + min(down, downRight);
    }
    int minPathSum(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> t(n, vector<int>(triangle.back().size(), -1));
        return solve(triangle, 0, 0, t);
    }
};