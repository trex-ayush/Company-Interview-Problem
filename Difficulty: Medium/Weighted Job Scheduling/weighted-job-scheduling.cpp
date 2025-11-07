class Solution {
  public:
    int BinarySearch(vector<vector<int>> &jobs, int key, int l, int r){
        while(l<=r){
            int m = l+(r-l)/2;
            if(jobs[m][0]>=key) r = m-1;
            else l = m+1;
        }
        return l;
    }
    int maxProfit(vector<vector<int>> &jobs) {
        int n = jobs.size();
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n+1, 0);
        for(int i = n-1;i>=0;i--){
            int r = jobs[i][1];
            int idx = BinarySearch(jobs, r, i+1, n-1);
            int pick = dp[idx] + jobs[i][2];
            int not_pick = dp[i+1];
            
            dp[i] = max(pick, not_pick);
        }
        return dp[0];
    }
};