class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        int prev1 = 0;
        int prev2 = 0;
        
        for(int i = 1; i < n; i++){
            int stepOne = prev1 + abs(height[i] - height[i - 1]);
            int stepTwo = INT_MAX;
            if(i > 1) stepTwo = prev2 + abs(height[i] - height[i - 2]);
            prev2 = prev1;
            prev1 = min(stepOne, stepTwo);;
        }
        
        return prev1;
    }
};