class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        // Step 2: Compute prefix sum
        vector<int> pre(n);
        pre[0] = arr[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + arr[i];
        }
        
        int ans = INT_MAX;
        int prev = 0;
        
        // Step 3: Try each element as the lower bound of the range
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                prev = pre[i - 1];
            }
            
            // Find the first element greater than arr[i] + k
            int pos = upper_bound(arr.begin() + i, arr.end(), arr[i] + k) - arr.begin();
            
            // Sum of elements to the right of pos
            int total = 0;
            if (pos > 0) {
                total = pre[n - 1] - pre[pos - 1];
            }
            
            // Allowed total value for elements > arr[i] + k
            int allowed = (n - pos) * (arr[i] + k);
            
            // Calculate extra coins needed
            int extraCoins = prev + total - allowed;
            
            // Update answer with minimum coins needed
            ans = min(ans, extraCoins);
        }
        return ans;
    }
};
