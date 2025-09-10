class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        unordered_map<char, int> mpp;
        int n = s.size();
        
        int maxLen = 0;
        int j = 0;
        int i = 0;
        
        while(j < n){
            mpp[s[j]]++;
            while(i < j && mpp[s[j]] > 1){
                mpp[s[i]]--;
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        
        return maxLen;
    }
};
