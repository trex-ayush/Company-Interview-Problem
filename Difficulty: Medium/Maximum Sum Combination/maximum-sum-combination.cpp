class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        
        priority_queue<pair<int, pair<int, int>>> pq; // {sum, {i,j}}
        set<pair<int,int>> set;
        vector<int> result;
        
        pq.push({a[0] + b[0], {0, 0}});
        set.insert({0, 0});
        
        while(result.size() < k){
            auto top = pq.top();
            pq.pop();
            
            int sum = top.first;
            int i   = top.second.first;
            int j   = top.second.second;
            
            result.push_back(sum);
            
            if(i + 1 < n && set.find({i+1, j}) == set.end()){
                pq.push({a[i+1] + b[j], {i+1, j}});
                set.insert({i+1, j});
            }
            if(j + 1 < n && set.find({i, j+1}) == set.end()){
                pq.push({a[i] + b[j+1], {i, j+1}});
                set.insert({i, j+1});
            }
        }
        
        return result;
    }
};