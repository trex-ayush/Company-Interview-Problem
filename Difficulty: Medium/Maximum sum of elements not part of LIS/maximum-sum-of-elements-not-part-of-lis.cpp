class Solution {
public:
    int nonLisMaxSum(vector<int>& arr) {
        int n     = arr.size();                            // number of elements
        int total = accumulate(arr.begin(), arr.end(), 0); // sum of all elements
        
        vector<int> dp(n, 1);                              // dp[i] = length of LIS ending at i (at least 1)
        vector<int> dpMinSum(n);                           // dpMinSum[i] = minimum sum of an LIS of length dp[i] ending at i
        
        for (int i = 0; i < n; i++) {
            dpMinSum[i] = arr[i];        // initialize with the element itself
        }
        
        int maxLIS    = 1;               // global maximum LIS length found so far
        int minLISsum = arr[0];          // minimum sum among all LIS of length maxLIS
        
        // build dp[] and dpMinSum[]
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    int currLen = dp[j] + 1;                   // potential new LIS length
                    int currSum = dpMinSum[j] + arr[i];        // corresponding sum
                    
                    if (currLen > dp[i]) {
                        dp[i]       = currLen;                 // update LIS length at i
                        dpMinSum[i] = currSum;                 // update min sum for this new length
                    }else if (currLen == dp[i]) {
                        // if same length, keep the smaller sum
                        dpMinSum[i] = min(dpMinSum[i], currSum);
                    }
                }
            }
            // update global maxLIS and its min sum
            if (dp[i] > maxLIS) {
                maxLIS    = dp[i];
                minLISsum = dpMinSum[i];
            }else if (dp[i] == maxLIS) {
                minLISsum = min(minLISsum, dpMinSum[i]);
            }
        }
        
        return total - minLISsum;        // sum of elements not in any minimal‐sum LIS
    }
};