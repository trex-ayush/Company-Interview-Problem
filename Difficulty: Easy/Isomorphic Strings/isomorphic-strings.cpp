class Solution {
  public:
    bool areIsomorphic(string &s, string &t) {
        int n = s.size();
        int m = t.size();
        
        if(n != m) return false;
        
        unordered_map<char,char> sTOt;
        unordered_map<char,char> tTOs;
        
        for(int i = 0; i < n; i++){
            int ch1 = s[i];
            int ch2 = t[i];
            
            if(sTOt.find(ch1) != sTOt.end() && sTOt[ch1] != ch2) return false;
            if(tTOs.find(ch2) != tTOs.end() && tTOs[ch2] != ch1) return false;
            
            sTOt[ch1] = ch2;
            tTOs[ch2] = ch1;
        }
        
        return true;
    }
};