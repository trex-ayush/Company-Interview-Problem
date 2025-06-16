class Solution {
  public:
    vector<int> rank;
    vector<int> parent;
    
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
        
        if(x_parent == y_parent){
            return;
        }
        
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }else {
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }
    
    int detectCycle(int V, vector<int> adj[]) {
        parent.resize(V);
        rank.resize(V);
        
        for(int i = 0; i < V; i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        for(int u = 0; u < V; u++){
            for(auto& v : adj[u]){
                if(u < v){
                    int p1 = find(u);
                    int p2 = find(v);
                    
                    if(p1 == p2) return true;
                    Union(u, v);
                }
            }
        }
        return false;
    }
};