class Solution {
  public:
    int getLPSLength(string &s) {
        int n = s.size();
        int i = 0, j = 1;
        int pos = j;
        
        while (j < n) {
            if (s[i] == s[j]) {
                i++;
                j++;
            } else {
                i = 0;
                pos++;  // move pos forward
                j = pos; // reset j to new pos
            }
        }
        return i; // return length of matched prefix suffix
    }
};