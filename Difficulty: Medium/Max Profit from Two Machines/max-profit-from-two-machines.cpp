class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        int n = a.size();
        
        vector<vector<int>> task(n, vector<int>(3));
        
        // Store profits and absolute difference
        for (int i = 0; i < n; i++) {
            task[i][0] = a[i];
            task[i][1] = b[i];
            task[i][2] = abs(a[i] - b[i]);
        }
        
        // Sort by descending order of difference
        sort(task.begin(), task.end(), [](vector<int> &t1, vector<int> &t2) {
            return t1[2] > t2[2];
        });
        
        int totalProfit = 0;
        
        for (int i = 0; i < n; i++) {
            int aProfit = task[i][0];
            int bProfit = task[i][1];
            
            // Assign to machine giving higher profit
            if (aProfit > bProfit) {
                
                if (x > 0) {
                    totalProfit += aProfit;
                    x--;
                } else {
                    totalProfit += bProfit;
                    y--;
                }
                
            } else {
                
                if (y > 0) {
                    totalProfit += bProfit;
                    y--;
                } else {
                    totalProfit += aProfit;
                    x--;
                }
            }
        }
        
        return totalProfit;
    }
};