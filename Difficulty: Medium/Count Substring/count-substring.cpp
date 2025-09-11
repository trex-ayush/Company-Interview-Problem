class Solution {
  public:
    int countSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        
        int i = 0;
        int j = 0;
        
        int count = 0;
        
        while(j < n){
            mpp[s[j]]++;
            while(i < n && mpp.size() == 3){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
                count += (n - j);
            }
            j++;
        }
        
        return count;
    }
};