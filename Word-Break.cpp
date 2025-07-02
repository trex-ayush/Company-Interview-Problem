class Solution {
public:
    int t[301];
    bool solve(string& s, unordered_set<string>& st, int idx){
        int n = s.size();
        if(idx >= n) return true;

        if(t[idx] != -1) return t[idx];

        if(st.find(s) != st.end()) return true;
        
        for(int L = 1; L <= n; L++){
            string temp = s.substr(idx, L);
            if(st.find(temp) != st.end() && solve(s, st, idx+L)) return t[idx] = true;
        }
        return t[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        memset(t, -1, sizeof(t));
        
        for(auto& word : wordDict){
            st.insert(word);
        }

        return solve(s, st, 0);
    }
};