class Solution {
public:
    int countIncreasing(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return 0;
        int left = 0, right = 1, cnt = 0;
        
        while (right < n) {
            if (arr[right - 1] < arr[right]) cnt += (right - left);
            else left = right;
            
            right++;
        }
        
        return cnt;
    }
};