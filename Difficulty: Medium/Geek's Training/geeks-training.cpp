class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> t(n, vector<int>(4, 0));
        
        // day 0
        t[0][0] = max(arr[0][1], arr[0][2]);
        t[0][1] = max(arr[0][0], arr[0][2]);
        t[0][2] = max(arr[0][0], arr[0][1]);
        t[0][3] = max({arr[0][0], arr[0][1], arr[0][2]});
        
        for(int day = 1; day < n; day++){
            for (int lastTask = 0; lastTask < 4; lastTask++) {
                t[day][lastTask] = 0;
                for(int task = 0; task < 3; task++){
                    if(task != lastTask){
                        int point = arr[day][task] + t[day-1][task];
                        t[day][lastTask] = max(t[day][lastTask], point);
                    }
                }
            }
        }
        return t[n - 1][3];
    }
};
