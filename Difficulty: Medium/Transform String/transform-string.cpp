class Solution {
  public:
    int transform(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        
        if(s1 == s2) return 0;
        if(n != m) return -1;
        
        int freq[256] = {0};
        
        for (char c : s1) freq[c]++;
        for (char c : s2) freq[c]--;
        
        for (int i = 0; i < 256; i++) {
            if (freq[i] != 0) return -1;
        }
        
        int res = 0;
        
        int i = n - 1;
        int j = m - 1;
        
        while(i >= 0) {
            if(s1[i] == s2[j]){
                i--;
                j--;
                res++;
            }else i--;
        }
        
        
        return n - res;
    }
};
