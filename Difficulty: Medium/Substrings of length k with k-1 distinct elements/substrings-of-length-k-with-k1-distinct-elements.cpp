class Solution {
  public:
    // Time complexity:  O(n)
    // Space complexity: O(26) = O(1)
    int substrCount(string &s, int k) {
        int n = s.length();
        int result = 0;
        unordered_map<char, int> mpp;  // O(26)
        
        int i = 0;
        int j = 0;
        
        while(j < n){
            mpp[s[j]]++;
            if(j-i+1 == k){
                if(mpp.size() == k - 1){
                    result += 1;
                }
            }else  if(j-i+1 > k){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0){
                    mpp.erase(s[i]);
                }
                i++;
                if(mpp.size() == k - 1){
                    result += 1;
                }
                
            }
            j++;
        }
        
        return result;
    }
};