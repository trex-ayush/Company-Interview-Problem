class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int maxLen = INT_MIN;
        
        int i = 0;
        int j = 0;
        
        while(j < n){
            if(arr[j] == 0) k--;
            
            while(i < n && k < 0){
                if(arr[i] == 0) k++;
                i++;
            }
            maxLen = max(j - i + 1, maxLen);
            j++;
        }
        return maxLen;
    }
};
