class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if (totalSum % 2 != 0) return false;  // Odd total cannot be split evenly
        
        int target = totalSum / 2;
        int currentSum = 0;
        
        for (int num : arr) {
            currentSum += num;
            if (currentSum == target) {
                return true;
            }
        }
        return false;
    }
};