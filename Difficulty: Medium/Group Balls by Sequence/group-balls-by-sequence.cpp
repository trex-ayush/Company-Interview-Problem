class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        int n = arr.size();
        if(n % k) return false;
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++){
            if(arr[i] == -1) continue;
            
            int curr = arr[i];
            int count = 0;
            
            for(int j = i; j < n; j++){
                if(arr[j] == curr){
                    curr++;
                    count++;
                    arr[j] = -1;
                    if(count == k) break;
                }
            }
            
            if(count != k) return false;
        }
        
        return true;
    }
};
