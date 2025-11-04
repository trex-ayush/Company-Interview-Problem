class Solution {
  public:
    unordered_map<int, int> t;
    int solve(vector<int>& height, int idx){
        if(idx == 0) return 0;
        if(t.find(idx) != t.end()) return t[idx];

        int stepOne = INT_MAX, stepTwo = INT_MAX;
        if(idx - 1 >= 0) {
            stepOne = solve(height, idx - 1) + abs(height[idx] - height[idx-1]);
        }
        if(idx - 2 >= 0) {
            stepTwo = solve(height, idx - 2) + abs(height[idx] - height[idx-2]);
        }
        return t[idx] = min(stepOne, stepTwo);
    }
    int minCost(vector<int>& height) {
        return solve(height, height.size() - 1);
    }
};