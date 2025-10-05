class Solution {
public:
    // T.C : O(n*n)
    // S.C : O(n*n)
    vector<vector<int>> dirs = {{-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, -1}, {-2, 1}};
    bool valid(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    bool solve(vector<vector<int>>& grid, int i, int j, int count) {
        int n = grid.size();
        if (count == n * n - 1) return true;

        for (auto& dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];

            if (valid(x, y, grid) && grid[x][y] == count + 1) {
                if (solve(grid, x, y, count + 1)) return true;
            }
        }

        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return false;
        return solve(grid, 0, 0, 0);
    }
};
