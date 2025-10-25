class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i = 0; i < arr.size(); i++){
            pq.push(arr[i]);
        }
        int ans = 0;
        while(!pq.empty()){
            int first = pq.top();
            pq.pop();
            if(pq.empty()) return ans;
            int second = pq.top();
            pq.pop();
            int newLen = first + second;
            ans += newLen;
            pq.push(newLen);
        }
    }
};