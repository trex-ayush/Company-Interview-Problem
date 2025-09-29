class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();
        int ans = INT_MIN;
        deque <int> q;
        
        vector <int> pre(n+1, 0);
        for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + arr[i-1];
        
        for(int i = a; i <= n; i++){
            while(!q.empty() && q.front() + b < i) q.pop_front();
            while(!q.empty() && pre[q.back()] > pre[i-a]) q.pop_back();
            q.push_back(i-a);
            
            ans = max(ans, pre[i] - pre[q.front()]);
        }
        
        return ans;
    }
};