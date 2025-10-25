class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        unordered_map<int, int> mpp;
        
        int n = arr.size();
        int sum = 0;
        int cnt = 0;
        
        mpp[0] = 1;
        
        for(int i = 0; i < n; i++){
            sum += arr[i];
            
            if(mpp.find(sum) != mpp.end()){
                cnt += mpp[sum];
            }
            mpp[sum]++;
        }
        
        return cnt;
    }
};