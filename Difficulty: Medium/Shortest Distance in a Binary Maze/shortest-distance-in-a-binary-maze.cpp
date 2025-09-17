// User function Template for C++

class Solution {
  public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        if (source == destination) return 0;
        if (grid[destination.first][destination.second] == 0) return -1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        q.push({source.first, source.second});
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[source.first][source.second] = true;
        
        int result = 0;
        while(!q.empty()){
            int k = q.size();
            
            while(k--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(x == destination.first && y == destination.second) return result;
                
                for(auto& dir : dirs){
                    int i = x + dir[0];
                    int j = y + dir[1];
                    
                    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1 && !visited[i][j]){
                        visited[i][j] = true;
                        q.push({i, j});
                    }
                }
                
            }
            result += 1;
        }
        
        return -1;
    }
};
