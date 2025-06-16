// T.C: O(n*26) = O(n)
// S.C: O(26) = O(1)
class Solution {
public:
    vector<int> rank;
    vector<int> parent;

    int find(int x) {
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
        }else{
            parent[p2] = p1;
            rank[p1]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);

        for(int i = 0; i < 26; i++){
            parent[i] = i;
            rank[i] = 1;
        }

        // First pass: all '==' equations
        for (auto& eq : equations) {
            if (eq[1] == '=') {
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';
                Union(x, y);
            }
        }

        // Second pass: check all '!=' equations
        for (auto& eq : equations) {
            if (eq[1] == '!') {
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';
                if (find(x) == find(y)) return false;
            }
        }
        return true;
    }
};