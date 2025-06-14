// Company Tags: American Express
// T.C: O(n)
// S.C: O(h) where h is maximum height
class Solution {
public:
    long long solve(unordered_map<int,vector<int>>& adj, int& seats, int u, int parent, long long& ans){
        long long passenger = 1;

        for(auto& v : adj[u]){
            if(v != parent){
                long long people = solve(adj, seats, v, u, ans); 
                ans += ceil((people*1.0)/seats);
                passenger += people;
            }
        }
        return passenger;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long ans = 0;
        unordered_map<int,vector<int>> mpp;

        for(auto& road : roads){
            int u = road[0];
            int v = road[1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        solve(mpp,seats,0,-1,ans);

        return ans;
    }
};