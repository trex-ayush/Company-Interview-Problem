class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        unordered_map<int, int> mp;    // maps diff -> first index it was seen
        int sum1 = 0, sum2 = 0, result = 0;
        
        for (int i = 0; i < n; i++) {
            sum1 += a1[i];
            sum2 += a2[i];
            int diff = sum1 - sum2;
            
            if (diff == 0) {
                // from 0..i is balanced
                result = max(result, i + 1);
            }else if (mp.count(diff)) {
                // seen this diff before, subarray (mp[diff]+1..i) is balanced
                result = max(result, i - mp[diff]);
            }else {
                // first time seeing this diff
                mp[diff] = i;
            }
        }
        return result;
    }
};