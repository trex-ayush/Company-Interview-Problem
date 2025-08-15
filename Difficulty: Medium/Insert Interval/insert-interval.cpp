class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();
        
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0] , newInterval[0]);
            newInterval[1] = max(intervals[i][1] , newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);
        
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans;
    }
};
