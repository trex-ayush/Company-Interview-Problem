class Solution {
  public:
    string reverseWords(string &s) {
        int n = s.length();
        reverse(s.begin(), s.end());
        
        string res = "";
        
        for(int j = 0; j < n; j++){
            if(s[j] == '.'){
                continue;
            }
            string temp = "";
            while(j < n && s[j] != '.'){
                temp = s[j] + temp;
                j++;
            }
            if(res.length() == 0) res = temp;
            else res = res + '.' + temp;
        }
        return res;
    }
};