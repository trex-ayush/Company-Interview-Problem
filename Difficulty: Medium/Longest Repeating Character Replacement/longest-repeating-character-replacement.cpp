class Solution {
  public:
    int characterReplacement(string& s, int k) {
        int n = s.size();
        
        unordered_map<char, int> mpp;
        int maxFreq = 0;
        int i = 0;
        int j = 0;
        int maxLen = 0;
        
        while(j < n){
            mpp[s[j]]++;
            maxFreq = max(maxFreq, mpp[s[j]]);
            
            while((j-i+1) - maxFreq > k){
                mpp[s[i]]--;
                i++;
                // maxFreq = 0;
                // for(auto& mp : mpp) maxFreq = max(maxFreq, mp.second);
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        
        return maxLen;
    }
};