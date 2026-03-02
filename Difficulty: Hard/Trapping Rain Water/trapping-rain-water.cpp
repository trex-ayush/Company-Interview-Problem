class Solution {
  public:
    int maxWater(vector<int> &height) {
        int n = height.size();
        vector<int> lMaxi(n, -1);
        
        lMaxi[0] = height[0];
        for (int i = 1; i < n; i++) {
            lMaxi[i] = max(lMaxi[i - 1], height[i]);
        }
        
        vector<int> rMaxi(n, -1);
        rMaxi[n - 1] = height[n - 1];
        
        for (int i = n - 2; i >= 0; i--) {
            rMaxi[i] = max(rMaxi[i + 1], height[i]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int mini = min(lMaxi[i], rMaxi[i]);
            if (mini > height[i]) ans += (mini - height[i]);
        }
        
        return ans;
    }
};
