class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        unordered_map<int, int> mpp;
        vector<bool> visited(n*n + 1, false);
        
        queue<int> q;
        q.push(1);
        visited[1] = true;
        
        for (int i = 0; i < lad.size(); i += 2) {
            mpp[lad[i]] = lad[i + 1];
        }
        for (int i = 0; i < sn.size(); i += 2) {
            mpp[sn[i]] = sn[i + 1];
        }
        
        int steps = 0;
        
        while(!q.empty()){
            int k = q.size();
            
            while(k--){
                int curr = q.front();
                q.pop();
                if(curr == n*n) return steps;
                
                for(int i = 1; i <= 6; i++){
                    int next = curr + i;
                    if(next > n*n) break;
                    
                    if (mpp.count(next)) next = mpp[next];
                    
                    if(!visited[next]){
                        visited[next] = true;
                        q.push(next);
                    }
                }
                
            }
            steps++;
        }
        return -1;
    }
};