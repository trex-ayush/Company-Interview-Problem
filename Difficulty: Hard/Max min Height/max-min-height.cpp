// User function Template for C++

class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, int w, int targetHeight) {
        int         n = arr.size();
        vector<int> water(n + 1, 0);  // Difference array for efficient range addition
        int         daysUsed  = 0;
        int         currWater = 0;
        
        for (int i = 0; i < n; i++) {
            currWater += water[i];  // Add the effect of previous waterings
            int currHeight = arr[i] + currWater;
            if (currHeight < targetHeight) {
                int need = targetHeight - currHeight; // Water needed at this point
                daysUsed += need;
                if (daysUsed > k) {                   // If exceeded allowed waterings, not possible
                    return false;
                }
                currWater += need;        // Add immediate effect
                water[i]  += need;        // Start effect at i
                if (i + w <= n) {
                    water[i + w] -= need; // End effect after window
                }
            }
        }
        return true;
    }

    // Main function to maximize the minimum height
    int maxMinHeight(vector<int>& arr, int k, int w) {
        int low  = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end()) + k;
        
        int result = 0;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(arr, k, w, mid)) {
                result = mid;        // Try to go higher
                low    = mid + 1;
            } else {
                high = mid - 1;      // Try lower
            }
        }
        return result;
    }
};