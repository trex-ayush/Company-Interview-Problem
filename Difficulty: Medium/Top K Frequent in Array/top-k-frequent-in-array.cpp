class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mpp;
        
        for(auto& a : arr) mpp[a]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(auto& mp : mpp){
            pq.push({mp.second, mp.first});
            if(pq.size() > k) pq.pop();
        }
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
