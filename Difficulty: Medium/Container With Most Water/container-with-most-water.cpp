class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int res = 0;
        
        int i = 0;
        int j = n - 1;
        
        while(i < j){
            int w = (j - i);
            int h = min(arr[i], arr[j]);
            
            res = max(res, w*h);
            
            if(arr[i] < arr[j]) i++;
            else j--;
        }
        
        return res;
    }
};