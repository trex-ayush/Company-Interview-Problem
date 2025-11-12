class Solution {
public:
    bool wildCard(string &txt, string &pat) {
        int n = txt.size(), m = pat.size();
        
        // Step 1: collapse multiple '*'
        string newPat;
        for (int i = 0; i < m; i++) {
            if (pat[i] == '*' && !newPat.empty() && newPat.back() == '*')
                continue; // skip duplicate '*'
            newPat.push_back(pat[i]);
        }
        pat = newPat;
        m = pat.size();
        
        // Step 2: greedy match
        int i = 0, j = 0;   // i->text, j->pattern
        int starIdx = -1, iIdx = -1;
        
        while (i < n) {
            if (j < m && (pat[j] == txt[i] || pat[j] == '?')) {
                i++; j++;  // direct match
            } 
            else if (j < m && pat[j] == '*') {
                starIdx = j;
                iIdx = i;
                j++; // move pattern pointer
            }
            else if (starIdx != -1) {
                j = starIdx + 1;   // retry after last '*'
                iIdx++;
                i = iIdx;
            }
            else {
                return false; // no match
            }
        }
        
        // consume remaining stars in pattern
        while (j < m && pat[j] == '*') j++;
        
        return j == m;
    }
};