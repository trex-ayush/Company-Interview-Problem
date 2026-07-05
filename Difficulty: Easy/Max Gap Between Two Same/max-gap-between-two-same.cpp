class Solution {
  public:
    int maxCharGap(string &s) {
        int n = s.size();
        vector<int> freq(26, -1);
        int maxDist = -1;
        
        for(int i = 0; i < n; i++){
            if(freq[s[i] - 'a'] == -1) {
                freq[s[i] - 'a'] = i;
            } else maxDist = max(maxDist, i - freq[s[i] - 'a'] - 1);
        }
        
        return maxDist;
    }
};