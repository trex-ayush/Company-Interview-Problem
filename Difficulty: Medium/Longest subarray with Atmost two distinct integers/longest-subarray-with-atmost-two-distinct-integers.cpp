class Solution {
  public:
    // Time Complexity : O(n)
    // Space Complexity: O(3) = O(1) 
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        int result = 0;
        unordered_map<int, int> mpp; 
        
        int i = 0;
        int j = 0;
        
        while(j < n){
            mpp[arr[j]]++;
            
            while(mpp.size() > 2){
                mpp[arr[i]]--;
                if(mpp[arr[i]] == 0) {
                    mpp.erase(arr[i]);
                }
                i++;
            }
            if(mpp.size() <= 2){
                result = max(result, j-i+1);
            }
            
            j++;
        }
        
        return result;
    }
};