class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        
        for(auto& a : arr){
            sum += a;
            if(mpp.find(sum - k) != mpp.end()){
                count += mpp[sum - k];
            }
            mpp[sum]++;
        }
        
        return count;
    }
};
