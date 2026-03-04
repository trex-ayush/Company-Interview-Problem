class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size(), x = 0,maxi;
        for(int i = 0;i < k; i++){
            x ^= arr[i];
        }
        
        maxi = x;
        for(int i = k; i < n; i++){
            x ^= arr[i] ^ arr[i - k];
            if(x > maxi) maxi = x;
        }
        
        return maxi;
    }
};