class Solution {
public:
    int countTriangles(std::vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;
        sort(arr.begin(), arr.end());
        
        int count = 0;
        
        for (int k = n - 1; k >= 2; --k) {
            int l = 0;
            int r = k - 1;
            while (l < r) {
                if (arr[l] + arr[r] > arr[k]) {
                    count += r - l;
                    r--;
                } else {
                    l++;
                }
            }
        }
        return count;
    }
};