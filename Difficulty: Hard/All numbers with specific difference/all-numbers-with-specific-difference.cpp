class Solution {
public:
    bool isConditionMet(int x, int d) {
        int temp = x;
        int sum = 0;
        
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        
        return temp - sum >= d;
    }
    
    int getCount(int n, int d) {
        int res = 0;
        int l = 1, h = n;
        
        while (l <= h) {
            int m = l + (h - l) / 2;
            
            if (isConditionMet(m, d)) {
                res = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res == 0 ? 0 : n - res + 1;
    }
};
