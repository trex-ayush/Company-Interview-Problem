class Solution {
  public:
    string firstNonRepeating(string &s) {
        int n = s.length();
        vector<int> freq(26, 0);
        queue<int> q;
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            if(freq[s[i] - 'a'] == 1) q.push(s[i]);
            while(!q.empty() && freq[q.front() - 'a'] != 1) q.pop();
            if(!q.empty()) s[i] = q.front();
            else s[i] = '#';
        }
        return s;
    }
};