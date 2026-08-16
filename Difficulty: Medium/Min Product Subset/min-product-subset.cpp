class Solution {
  public:
    int minProd(vector<int>& arr) {
        int neg = 0;
        int minNeg = INT_MAX;
        int product = 1;
        bool zero = false;
        
        for (int x : arr) {
            if (x < 0) {
                neg++;
                minNeg = min(minNeg, abs(x));
                product *= x;
            } 
            else if (x == 0) zero = true;
            else product *= x;
            
        }
        
        if (neg == 0) {
            if (zero) return 0;
            return *min_element(arr.begin(), arr.end());
        }
        
        if (neg % 2 == 1) return product;
        
        return product / (-minNeg);
    }
};