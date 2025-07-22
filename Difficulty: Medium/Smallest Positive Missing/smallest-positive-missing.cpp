class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        bool one = false;
        
        for(int i = 0; i < n; i++){
            if(arr[i] == 1) one = true;
            if(arr[i] <= 0 || arr[i] > n) arr[i] = 1;
        }
        if(one == false) return 1;
            
        for(int i = 0; i < n; i++){
            int num = abs(arr[i]);
            int idx = num - 1;
            if(arr[idx] < 0) continue;
            else arr[idx] = -arr[idx];
        }
        for(int i = 0; i < n; i++){
            if(arr[i] > 0){
                return i+1;
            }
        }
        return n+1;
    }
};
