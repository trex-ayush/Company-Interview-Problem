class Solution {
  public:
    const int mod = 100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end) return 0;
        queue<int> q;
        unordered_set<int> visited;
        int level = 0;
        q.push(start);
        visited.insert(start);
        
        while(!q.empty()){
            int n = q.size();
            while(n--){
                int k = q.front();
                q.pop();
                
                for(int i = 0; i < arr.size(); i++){
                    int next = (k * arr[i]) % mod;
                    if(next == end) return level + 1;
                    if(visited.find(next) == visited.end()){
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
