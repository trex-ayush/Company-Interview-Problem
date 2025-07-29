class Solution {
  public:
    vector<int> asciirange(string& s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }
        
        vector<int> result;
        for (int c = 0; c < 26; c++) {
            if (first[c] != -1 && last[c] - first[c] > 1) {
                int sum_ascii = 0;
                for (int i = first[c] + 1; i < last[c]; i++) {
                    sum_ascii += s[i];
                }
                if (sum_ascii > 0) result.push_back(sum_ascii);
            }
        }
        
        return result;
    }

};