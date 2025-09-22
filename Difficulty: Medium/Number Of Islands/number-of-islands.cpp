class DisjointSet{
    vector<int> parent, rank;
  public:
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    
    int find(int x){
        if(x == parent[x]) return parent[x];
        return parent[x] = find(parent[x]);
    }
    
    void unionByRank(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        
        if(rank[u] < rank[v]){
            parent[u] = v;
        }else if(rank[u] > rank[v]){
            parent[v] = u;
        }else{
            parent[v] = u;
            rank[u]++;
        }
    }
};
class Solution {
  public:
    bool isValid(int& x, int& y, int& n, int& m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int cnt = 0;
        vector<int> res;
        vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        
        for(auto& op : operators){
            int row = op[0]; 
            int col = op[1];
            
            if(visited[row][col]){
                res.push_back(cnt);
                continue;
            }
            
            visited[row][col] = true;
            cnt++;
            
            for(auto& dir : dirs){
                int x = row + dir[0];
                int y = col + dir[1];
                if(isValid(x, y, n, m)){
                    if(visited[x][y]){
                        int nodeIdx = row * m + col;
                        int adjNodeIdx = x * m + y;
                        
                        int parentOfNodeIdx = ds.find(nodeIdx);
                        int parentOfAdjNodeIdx = ds.find(adjNodeIdx);
                        
                        if(parentOfNodeIdx != parentOfAdjNodeIdx){
                            cnt--;
                            ds.unionByRank(nodeIdx, adjNodeIdx);
                        }
                    }
                }
            }
            res.push_back(cnt);
        }
        
        return res;
    }
};
