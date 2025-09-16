// User function Template for C++

class Solution {
  public:
    int n, m;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int baseRow, int baseCol, vector<pair<int, int>>& temp){
        if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j] == true || grid[i][j] != 1) return;
        
        visited[i][j] = true;
        temp.push_back({i - baseRow, j - baseCol});
        
        for(auto& dir : dirs){
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            dfs(grid, visited, i_, j_, baseRow, baseCol, temp);
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        set<vector<pair<int, int>>> st; // storing indexs to track that if it exists or not
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    vector<pair<int, int>> temp;
                    dfs(grid, visited, i, j, i, j, temp);
                    st.insert(temp);
                }
            }
        }
        
        return st.size();
    }
};
