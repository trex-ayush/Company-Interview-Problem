class Solution {
  public:
    int count(string &s, int k){
        int n = s.length();
        int ans = 0;
        
        vector<int> freq(26, 0);
        int distinctCnt = 0;
        int i = 0;
        
        for (int j = 0; j < n; j++) {
            freq[s[j] - 'a']++;
            if (freq[s[j] - 'a'] == 1) distinctCnt++;
            
            while (distinctCnt > k) {
                freq[s[i] - 'a']--;
                if (freq[s[i] - 'a'] == 0) distinctCnt--;
                i++;
            }
        
            ans += j - i + 1;
        }
        
        return ans;
    }
    int countSubstr(string& s, int k) {
        int n = s.length();
        int ans = 0;
        
        ans = count(s, k) - count(s, k-1);
        
        return ans;
    }
};