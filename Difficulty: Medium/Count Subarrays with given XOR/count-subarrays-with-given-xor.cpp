class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        long count = 0;
        long Xor = 0;
        
        unordered_map<int,int> mpp;
        mpp[0]++;
        
        for(auto a : arr){
            Xor ^= a;
            if(mpp.find(Xor ^ k) != mpp.end()){
                count += mpp[Xor ^ k];
            }
            mpp[Xor]++;
        }
        return count;
    }
};
