// Company tags: Expedia, Tinkoff, Walmart Labs
class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int u){
        visited[u] = true;

        for(auto& v : rooms[u]){
            if(!visited[v]){
                dfs(rooms, visited, v);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(rooms, visited, 0);

        for(int i = 0; i < n; i++){
            if(!visited[i]) return false;
        }

        return true;
    }
};

// 0 -> 1, 3
// 1 -> 3, 0, 1
// 2 -> 3
// 3 -> 