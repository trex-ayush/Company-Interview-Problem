class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> prev(4, 0);
        
        // day 0
        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);
        prev[3] = max({arr[0][0], arr[0][1], arr[0][2]});
        
        for(int day = 1; day < n; day++){
            vector<int> temp (4, 0);
            for (int lastTask = 0; lastTask < 4; lastTask++) {
                temp[lastTask] = 0;
                for(int task = 0; task < 3; task++){
                    if(task != lastTask){
                        int point = arr[day][task] + prev[task];
                        temp[lastTask] = max(temp[lastTask], point);
                    }
                }
            }
            prev = temp;
        }
        return prev[3];
    }
};
