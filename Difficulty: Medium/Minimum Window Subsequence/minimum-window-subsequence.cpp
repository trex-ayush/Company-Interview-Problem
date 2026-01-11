class Solution {
  public:
  

 
    int solve(int i, int j,string& s1, string& s2) {

        
        if (j < 0) return i+1;

      
        if (i < 0) return -1;

        if (s1[i] == s2[j])
            return solve(i - 1, j - 1,s1,s2);
        else
            return solve(i - 1, j,s1,s2);
    }

 
    
  
    string minWindow(string& s1, string& s2) {
        // Code here
        
        int n = s1.size();
       int m = s2.size();

        int bestLen = INT_MAX;
        int bestStart = -1;

        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[m - 1]) {

                int start = solve(i, m - 1,s1,s2);

                if (start != -1) {
                    int len = i - start + 1;
                    if (len < bestLen) {
                        bestLen = len;
                        bestStart = start;
                    }
                }
            }
        }

        if (bestStart == -1) return "";
        return s1.substr(bestStart, bestLen);
    
    }
};