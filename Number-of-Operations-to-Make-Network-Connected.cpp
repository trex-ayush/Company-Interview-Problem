// Company tags: Amazon, Akuna Capital, Paytm, Intuit, IBM, Nvidia
// T.C: O(n)
// S.C: O(n)
class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int p1 = find(x);
        int p2 = find(y);

        if(p1 == p2) return;

        if(rank[p1] > rank[p2]){
            parent[p2] = p1;
        }else if(rank[p1] < rank[p2]){
            parent[p1] = p2;
        }else {
            parent[p2] = p1;
            rank[p1]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int len = connections.size();
        if(n - 1 > len) return -1;
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
 
        int components = n;

        for(auto& connection : connections){
            int n1 = connection[0];
            int n2 = connection[1];
            int p1 = find(n1);
            int p2 = find(n2);

            if(p1 == p2) continue;
            Union(n1, n2);
            components--;
        }

        return components - 1;
    }
};