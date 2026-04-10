class Solution {
public:
    vector<int> find3Numbers(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftMin(n);
        vector<int> rightMax(n);
        
        leftMin[0] = arr[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(arr[i], leftMin[i - 1]);
        }
        rightMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(arr[i], rightMax[i + 1]);
        }
        for (int i = 1; i < n - 1; i++) {
            if (leftMin[i - 1] < arr[i] && arr[i] < rightMax[i + 1]) {
                return {leftMin[i - 1], arr[i], rightMax[i + 1]};
            }
        }
        return {};
    }
};
