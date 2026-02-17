class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        int maxTime = 0;
        for (auto &vec : arr) {
            maxTime = max(maxTime, vec[1]);
        }
        
        vector<int> diffArray(maxTime + 2, 0);
        
        for (auto &interval : arr) {
            int startTime = interval[0];
            int endTime   = interval[1];
            
            diffArray[startTime]++;      // meeting starts
            diffArray[endTime + 1]--;    // meeting ends AFTER endTime
        }
        
        int active = 0, ans = 0;
        for (int x : diffArray) {
            active += x;
            ans = max(ans, active);
        }
        
        return ans;
    }
};
