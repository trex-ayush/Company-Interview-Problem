class Solution {
private:
    int solve(unordered_map<int,vector<pair<int,int>>>& adj, int src, int dst, int k,vector<int>& distance){
        queue<pair<int,int>> q;  // {node , cost};
        q.push({src,0});
        distance[src] = 0;
        int step = 0;

        while(!q.empty() && step <= k){
            int n = q.size();
            while(n--){
                auto temp = q.front();
                q.pop();
                int u = temp.first;
                int d = temp.second;

                for(auto& neigh : adj[u]){
                    int v         = neigh.first;
                    int neighCost = neigh.second;
                    if(distance[v] > neighCost + d){
                        distance[v] = neighCost + d;
                        q.push({v , neighCost + d});
                    }
                }
            }
            step++;
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        vector<int> distance(n,INT_MAX);

        for(auto& flight : flights){
            int u = flight[0];
            int v = flight[1];
            int c = flight[2];
            adj[u].push_back({v,c});
        }
        return solve(adj,src,dst,k,distance);  
    }
};