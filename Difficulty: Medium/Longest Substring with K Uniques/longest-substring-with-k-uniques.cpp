class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        
        unordered_map<char, int> mpp;
        int i = 0;
        int j = 0;
        
        int result = -1;
        
        while(j < n){
            mpp[s[j]]++;
            while(mpp.size() > k){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0){
                    mpp.erase(s[i]);
                }
                i++;
            }
            if(mpp.size() == k){
                result = max(result, j-i+1);
            }
            j++;
        }
        
        return result;
    }
};