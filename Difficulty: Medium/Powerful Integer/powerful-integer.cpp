class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        int ans = -1;
        map<int, int> prefix;
        
        for (auto& interval : intervals) {
            int st = interval[0];
            int en = interval[1];
            prefix[st]++;
            prefix[en + 1]--;
        }
        
        int curr = 0;
        for (auto& [i, val] : prefix) {
            if (curr >= k && curr + val < k) {
                ans = i - 1;
            }
            curr += val;
            if (curr >= k) {
                ans = i;
            }
        }
        
        return ans;
    }
};
