class Solution {
public:
    string smallestWindow(string &s, string &p) {
        int n = s.size();
        int m = p.size();
        
        if(m > n) return "";
        
        unordered_map<char, int> mpp;
        for (char ch : p) mpp[ch]++;
        
        int minLen = INT_MAX;
        int start_i = 0;
        int i = 0, j = 0;
        
        int count = p.size();  // total characters to match
        
        while (j < n) {
            char ch = s[j];
            
            if (mpp[ch] > 0) {
                count--;
            }
            mpp[ch]--;
            
            // try to shrink the window
            while (count == 0) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start_i = i;
                }
                
                // shrink from left
                mpp[s[i]]++;
                if (mpp[s[i]] > 0) {
                    count++;
                }
                i++;
            }
            j++;
        }
        
        return minLen == INT_MAX ? "" : s.substr(start_i, minLen);
    }
};
