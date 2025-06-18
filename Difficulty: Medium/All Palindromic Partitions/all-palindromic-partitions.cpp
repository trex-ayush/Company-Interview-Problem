class Solution {
  public:
    bool isPalindrome(string& s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string &s, int idx, vector<string>& temp, vector<vector<string>>& ans){
        int n = s.length();
        
        if(idx == n) {
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx; i < n; i++){
            if(isPalindrome(s, idx, i)){
                temp.push_back(s.substr(idx, i-idx+1));
                solve(s, i+1, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> palinParts(string &s){
        vector<vector<string>> ans;
        vector<string> temp;
        
        solve(s, 0, temp, ans);
        
        return ans;
    }
};