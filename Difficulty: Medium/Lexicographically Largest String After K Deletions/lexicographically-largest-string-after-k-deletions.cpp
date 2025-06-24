class Solution {
  public:
    string maxSubseq(string& s, int k) {
        int n = s.length();
        string ans = "";
        int removeChar = k;
        
        for(int i = 0; i < n; i++){
            while(!ans.empty() && ans.back() < s[i] && removeChar > 0){
                ans.pop_back();
                removeChar--;
            }
            if(ans.length() == 0){
                ans.push_back(s[i]);
            }else ans.push_back(s[i]);
        }
        
        ans.resize(n - k);
        return ans;
    }
};
