class Solution {
public:
    void solve(string s, int idx, vector<vector<string>>& result, vector<string> temp, vector<vector<bool>>& t){
        if(idx >= s.size()){
            result.push_back(temp);
            return;
        }
        
        for(int i = idx; i < s.size(); i++){
            if(t[idx][i]){
                temp.push_back(s.substr(idx, i-idx+1));
                solve(s, i+1, result, temp, t);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++) {
            t[i][i] = true;
        }
        
        for(int L = 2; L <= n; L++){
            for(int i = 0; i + L - 1 < n; i++){
                int j = i + L - 1;
                if(i == j){
                    // 1 length -> a,c,b,d
                    t[i][j] = true;
                }else if(L == 2){
                    if(s[i] == s[j]){
                        // 2 length -> aa,bb
                        t[i][j] = true;
                    }else{
                        t[i][j] = false;
                    }
                }else {
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]);
                }
            }
        }

        vector<vector<string>> result;
        solve(s, 0, result, {}, t);
        return result;
    }
};