
// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        int result = 0;
        int prefix = 0;
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] > k) prefix++;
            else prefix--;
            
            if(prefix > 0){
                result = max(result , i + 1);
            }
            
            if(mpp.find(prefix - 1) != mpp.end()){
                result = max(result, i - mpp[prefix-1]);
            }
            if(mpp.find(prefix) == mpp.end()){
                mpp[prefix] = i;
            }
        }
        return result;
    }
};

