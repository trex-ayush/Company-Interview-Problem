class Solution {
public:
    bool sameFreq(string& s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
        unordered_map<int, int> freqCount;
        for (int f : freq) {
            if (f > 0) freqCount[f]++;
        }
        
        if (freqCount.size() == 1) return true;
        
        if (freqCount.size() == 2) {
            auto it = freqCount.begin();
            int f1 = it->first, c1 = it->second;
            ++it;
            int f2 = it->first, c2 = it->second;
            
            // Case 1: One char occurs once (e.g., f = 1) and only one such char
            if ((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1)) return true;
            
            // Case 2: Frequencies differ by 1 and higher frequency occurs once
            if ((abs(f1 - f2) == 1) && ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1))) return true;
        }
        
        return false;
    }
};
