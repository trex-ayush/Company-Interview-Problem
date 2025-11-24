class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) { // constructor is used for initialization
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int i) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    void unionset(int x, int y) { // union keyword exists, so using unionset
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) return;

        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent; // x ka parent y
        }
        else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent; // y ka parent x
        }
        else {
            rank[x_parent]++;            // jiska rank badao, usko parent banao
            parent[y_parent] = x_parent; // y ka parent x
        }
    }
};

class Solution {
  public:
    // ----------------------------------------------------------
    // Build MST but SKIP exactly one edge (skipIndex)
    // ----------------------------------------------------------
    int buildMST(int V, vector<vector<int>>& edges, int skipIndex) {
        DSU dsu(V);
        int sum = 0;
        int usedEdges = 0;
        
        for (int i = 0; i < edges.size(); i++) {
            if (i == skipIndex) continue; // skip the chosen MST edge
            
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            if (dsu.find(u)!=dsu.find(v)) {
                dsu.unionset(u, v);
                sum += wt;
                usedEdges++;
            }
        }
        
        // If we didn't use V-1 edges → not a valid MST
        if (usedEdges != V - 1) return INT_MAX;
        return sum;
    }
    // ----------------------------------------------------------
    // Use Kruskal to find FIRST MST and which edges were used
    // ----------------------------------------------------------
    int firstMST(int V, vector<vector<int>>& edges, vector<int> &picked) {
        DSU dsu(V);
        int sum = 0;
        int used = 0;
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            if (dsu.find(u)!=dsu.find(v)) {
                dsu.unionset(u, v);
                sum += w;
                picked.push_back(i);  // store index of MST edge
                used++;
            }
        }
        
        // If MST does not contain V - 1 edges → graph disconnected
        if (used != V - 1) return -1;
        return sum;
    }

    // ----------------------------------------------------------
    // SECOND MST CALCULATION (Your Format)
    // ----------------------------------------------------------
    int secondMST(int V, vector<vector<int>> &edges) {
        // Sort edges by weight (required)
        auto cmp=[&](vector<int>&v1,vector<int>&v2){
            return v1[2]<v2[2];
        };
        sort(edges.begin(),edges.end(),cmp);
        
        // Step 1: Compute First MST and record its edges
        vector<int> picked;
        int mst1 = firstMST(V, edges, picked);
        
        if (mst1 == -1) return -1; // graph disconnected
        
        int secondBest = INT_MAX;
        
        // Step 2: Try removing each MST edge
        for (int &idx : picked) {
            int mst2 = buildMST(V, edges, idx);
            
            if (mst2 > mst1) {
                secondBest = min(secondBest, mst2);
            }
        }
        
        return (secondBest == INT_MAX ? -1 : secondBest);
    }
};