class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int missingNum = 1;
        int idx = 0;
        
        while(idx < arr.size() && k > 0){
            if(arr[idx] == missingNum){
                idx++;
            }else{
                k--;
            }
            missingNum++;
        }
        while(k--){
            missingNum++;
        }
        return missingNum - 1;   
    }
};